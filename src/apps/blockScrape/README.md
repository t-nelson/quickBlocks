## blockScrape

***
**Note:** This tool is available through [our website](http://quickblocks.io). Contact us at [sales@greathill.com](mailto:sales@greathill.com) for more information.
***

The `blockScrape` app queries your local node (or the ${FALLBACK} node if configured) using the RPC interface reading each block from any EVM-based blockchain. After extensive optimizations to the data, including <img width=500px align="right" src="docs/image.png"> determining each transaction's error status and expanding internal message calls, the blocks are stored in a speed-optimized database for fast retrieval. By doing as much work as possible prior to storage, QBlocks is able to achieve significant increases in speed of retrieval over the node.


Using operating system tools such as Linux's `cron` you can easily maintain a  constantly fresh QBlocks database. Using QBlocks `display strings` technology, it is even easy to populate a regular web 2.0 database and from there a full featured website representing the full state of your smart contract.

#### Usage

`Usage:`    blockScrape [-n|-s|-e|-m|-v|-h]  
`Purpose:`  Decentralized blockchain scraper and block cache.
             
`Where:`  

| Short Cut | Option | Description |
| -------: | :------- | :------- |
| -n | --noWrite | do not write binary blocks to disc (default: write the blocks) |
| -s | --start val | first block to visit (default: last visited block + 1) |
| -e | --end val | last block to visit (required if --start supplied) |
| -m | --maxBlocks val | maximum number of blocks to process (defaults to 5000) |
| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |

#### Other Options

All **QBlocks** command-line tools support the following commands (although in some case, they have no meaning):

    Command     |     Description
    -----------------------------------------------------------------------------
    --version   |   display the current version of the tool
    --nocolor   |   turn off colored display
    --wei       |   specify value in wei (the default)
    --ether     |   specify value in ether
    --dollars   |   specify value in US dollars
    --file:fn   |   specify multiple sets of command line options in a file.

<small>*For the `--file:fn` option, place a series of valid command lines in a file and use the above options. In some cases, this option may significantly improve performance. A semi-colon at the start of a line makes that line a comment.*</small>

**Powered by Qblocks<sup>&trade;</sup>**


