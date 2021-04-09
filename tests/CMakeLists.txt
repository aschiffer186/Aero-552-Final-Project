add_executable(regex_parser_test regex_parser_tests.cpp)
target_include_directories(regex_parser_test PRIVATE ${FINAL_PROJECT_SOURCE_DIR}/include/)
target_link_libraries(regex_parser_test PRIVATE Compiler)

add_executable(nfa_test nfa_test.cpp)
target_include_directories(nfa_test PRIVATE ${FINAL_PROJECT_SOURCE_DIR}/include/)
target_link_libraries(nfa_test PRIVATE Compiler)

#add_executable(dfa_test dfa_test.cpp)
#target_include_directories(dfa_test PRIVATE ${FINAL_PROJECT_SOURCE_DIR}/include/)
#target_link_libraries(dfa_test PRIVATE Compiler)

#add_test(NAME "Regex Parser Test" COMMAND regex_parser_test)