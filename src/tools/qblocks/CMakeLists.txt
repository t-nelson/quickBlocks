# minimum cmake version supported
cmake_minimum_required (VERSION 2.6)

# application project
project (qblocks)

# The sources to be used
file(GLOB SOURCE_FILES "*.cpp")

# Output
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/../bin")

# Define the executable to be generated
set(TOOL_NAME "qblocks")
set(PROJ_NAME "tools")
add_executable(${TOOL_NAME} ${SOURCE_FILES})

# Add the project static libs at linking
target_link_libraries (${TOOL_NAME} ${BASE_LIBS})

# Testing
# Define paths to test folder and gold folder
set(TEST_EXE "${EXECUTABLE_OUTPUT_PATH}/${TOOL_NAME}")
set(TEST_PATH "${TEST_PATH}/${PROJ_NAME}/${TOOL_NAME}")
set(GOLD_PATH "${GOLD_PATH}/${PROJ_NAME}/${TOOL_NAME}")

# Additional target to make the README.md
build_readme(${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_NAME})

# To run only specific tests we define a test configuration named "test_all"
add_custom_target(test-all COMMAND ${CMAKE_CTEST_COMMAND} -C test_all)

# Function to run an special or slow test case
function(run_special_test testName)
    run_the_special_test(${TEST_PATH} ${GOLD_PATH} ${testName} ${TEST_EXE} ${ARGN})
endfunction(run_special_test)

# Function to run an individual test case
function(run_test testName)
    run_the_test(${TEST_PATH} ${GOLD_PATH} ${testName} ${TEST_EXE} ${ARGN})
endfunction(run_test)

# Enter one line for each individual test
run_test("qblocks_README"        "-th")
run_test("qblocks_help"          "--help")
run_test("qblocks_invalid"       "--invalid")
run_test("qblocks_block_help"    "block"    " -h")
run_test("qblocks_trans_help"    "trans"    " -h")
run_test("qblocks_receipt_help"  "receipt"  " -h")
run_test("qblocks_logs_help"     "logs"     " -h")
run_test("qblocks_trace_help"    "trace"    " -h")
run_test("qblocks_bloom_help"    "bloom"    " -h")
run_test("qblocks_accounts_help" "accounts" " -h")
run_test("qblocks_balance_help"  "balance"  " -h")
run_test("qblocks_tokenbal_help" "tokenbal" " -h")
run_test("qblocks_contract_help" "contract" " -h")
run_test("qblocks_names_help"    "name"     " -h")
run_test("qblocks_when_help"     "when"     " -h")
run_test("qblocks_where_help"    "where"    " -h")

# Installation steps
install(TARGETS ${TOOL_NAME} RUNTIME DESTINATION bin)