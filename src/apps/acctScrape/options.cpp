/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *------------------------------------------------------------------------*/
#include "options.h"

//---------------------------------------------------------------------------------------------------
static COption params[] = {
    COption("-maxBlocks:<val>",  "the maximum number of blocks to visit during this run"),
    COption("-oneBlock:<val>",   "check if the block would be a hit"),
    COption("-oneTra(n)s:<val>", "check if the block and transaction would be a hit"),
    COption("-writeBlocks",      "write binary blocks to cache (default: do not write blocks)"),
    COption("-all",              "scan to the end of the blockchain (ignore --maxBlocks)"),
    COption("-noBloom(s)",       "do not use adaptive enhanced blooms (much faster if you use them)"),
    COption("@checkAddrs",       "use the per-block address lists (disabled)"),
    COption("@logLevel:<val>",   "specify the log level (default 1)"),
    COption("",                  "Index transactions for a given Ethereum address (or series of addresses).\n"),
};
static size_t nParams = sizeof(params) / sizeof(COption);

//---------------------------------------------------------------------------------------------------
bool COptions::parseArguments(string_q& command) {

    if (!standardOptions(command))
        return false;

    bool isAll = false;

    Init();
    while (!command.empty()) {
        string_q arg = nextTokenClear(command, ' ');
        if (startsWith(arg, "-m:") || startsWith(arg, "--maxBlocks:")) {
            nextTokenClear(arg,':');
            if (isUnsigned(arg))
                maxBlocks = str_2_Uint(arg);
            else
                return usage("Please provide an integer value of maxBlocks. Quitting...");

        } else if (startsWith(arg, "-o:") || startsWith(arg, "--oneBlock:")) {
            nextTokenClear(arg,':');
            if (isUnsigned(arg))
                oneBlock = str_2_Uint(arg);
            else
                return usage("Please provide an integer value for oneBlock. Quitting...");

        } else if (startsWith(arg, "-n:") || startsWith(arg, "--oneTrans:")) {
            nextTokenClear(arg,':');
            if (isUnsigned(arg))
                oneTrans = str_2_Uint(arg);
            else
                return usage("Please provide an integer value for oneTrans. Quitting...");

        } else if (startsWith(arg, "-l:") || startsWith(arg, "--level:")) {
            nextTokenClear(arg,':');
            if (isUnsigned(arg))
                logLevel = str_2_Uint(arg);
            else
                return usage("Please provide an integer value for --logLevel. Quitting...");

        } else if (arg == "-c" || arg == "--checkAddrs") {
            checkAddrs = true;

        } else if (arg == "-a" || arg == "--all") {
            isAll = true;

        } else if (arg == "-s" || arg == "--noBlooms") {
            ignoreBlooms = true;

        } else if (arg == "-w" || arg == "--writeBlocks") {
            writeBlocks = true;

        } else if (startsWith(arg, '-')) {  // do not collapse
            if (!builtInCmd(arg)) {
                return usage("Invalid option: " + arg);
            }
        }
    }

//#define WHICH_BLOCK 4759050
//#define WHICH_TRANS 199
#ifdef WHICH_BLOCK
    visitor.opts.oneBlock = WHICH_BLOCK;
#ifdef WHICH_TRANS
    visitor.opts.oneTrans = WHICH_TRANS;
#endif
#endif

    if (oneTrans && !oneBlock)
        return usage("If you specify oneTrans, you must specify oneBlock. Quitting...");

    if (isAll && oneBlock)
        return usage("Choose either --all or --oneBlock, not both. Quitting...");

    CBlock latest;
    getBlock(latest, "latest");
    lastTimestamp = latest.timestamp;

    if (isAll)
        maxBlocks = INT_MAX;

    // Note: Pick up these defaults from the blockScrape application settings.

    // If writeBlocks is true, then the user told us what to do on the command line and we obey them. If it's false
    // then we check to see if the config file for blockScrape is set to write blocks. If the blockScraper is writing
    // blocks, we don't have to. If not, then we do want to write blocks here (therefore we negate the config value).
    if (!writeBlocks)
        writeBlocks = !getGlobalConfig("blockScrape")->getConfigBool("settings", "writeBlocks", true);

    // Exclusions are always picked up from the blockScraper
    exclusions = toLower(getGlobalConfig("blockScrape")->getConfigStr("exclusions", "list", ""));

    if (!isParity() || !nodeHasTraces())
        return usage("This tool will only run if it is running against a Parity node that has tracing enabled. Quitting...");

    return true;
}

//---------------------------------------------------------------------------------------------------
void COptions::Init(void) {
    paramsPtr = params;
    nParamsRef = nParams;

    lastBlock     = 0;
    minWatchBlock = 0;
    maxWatchBlock = UINT32_MAX;
    maxBlocks     = 10000;
    minArgs       = 0;
    oneBlock      = 0;
    oneTrans      = 0;
    lastTimestamp = 0;
    writeBlocks   = false;
    checkAddrs    = false;
    ignoreBlooms  = false;
    firstBlock    = 0;
    nBlocks       = 0;
    blockCounted  = false;
    debugging     = 0;
    logLevel      = 1;
}

//---------------------------------------------------------------------------------------------------
COptions::COptions(void) : blkStats(), addrStats(), transStats(), traceStats(), txCache(WRITING_ARCHIVE) {
    Init();
}

//--------------------------------------------------------------------------------
COptions::~COptions(void) {
}

