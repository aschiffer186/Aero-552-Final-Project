#include "automata/regex_parser.hh"
#include "automata/nfa.hh"
#include "unit_test_framework.hh"

#include <sstream>

using nfa = final_project::automata::nfa;
using regex_parser = final_project::regex::regex_parser;

TESTING_SETUP()

BEGIN_TEST(NFA_Generator_1, Single character NFA)
    std::string regex = "a";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'a'}, {1}, {{{'a', {1}}}}};
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

BEGIN_TEST(NFA_Generator_Concatenate_1, Concatenation - simplest case)
    std::string regex = "ab";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'a', 'b'}, {2}, {{{'a', {1}}}, {{'b', {2}}}}};
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    std::cout << str_out.str();
    std::cout << expected_out.str();
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

BEGIN_TEST(NFA_Generator_Concatentate_2, Concatenation with alternation)
    std::string regex = "a(b|a)";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'a', 'b'}, {6},
        {
            {{'a', {1}}},
            {{final_project::automata::EPSILON, {2, 4}}},
            {{'b', {3}}},
            {{final_project::automata::EPSILON, {6}}},
            {{'a', {5}}},
            {{final_project::automata::EPSILON, {6}}}
        }
    };
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    std::cout << str_out.str();
    std::cout << expected_out.str();
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

BEGIN_TEST(NFA_Generator_Alternation_1, Alternation - simplest case)
    std::string regex = "a|b";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'a', 'b'}, {5}, 
        {
            {{final_project::automata::EPSILON, {1, 3}}},
            {{'a', {2}}},
            {{final_project::automata::EPSILON, {5}}},
            {{'b', {4}}}, 
            {{final_project::automata::EPSILON, {5}}}
        }
    };
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    std::cout << str_out.str();
    std::cout << expected_out.str();
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

BEGIN_TEST(NFA_Generator_Alternation_2,  Alternation with concatentation)
    std::string regex = "ab|b";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'a', 'b'}, {6},
        {
            {{final_project::automata::EPSILON, {1, 4}}},
            {{'a', {2}}},
            {{'b', {3}}}, 
            {{final_project::automata::EPSILON, {6}}},
            {{'b', {5}}},
            {{final_project::automata::EPSILON, {6}}}
        }
    };
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    std::cout << str_out.str();
    std::cout << expected_out.str();
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

BEGIN_TEST(NFA_Generator_Alternation_3, Nested alternation operator)
    std::string regex = "a|b|c";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
END_TEST()

BEGIN_TEST(NFA_Generator_Alternation_4, Alternation with Kleene closure)
    std::string regex = "a*|b";
END_TEST()

BEGIN_TEST(NFA_Generator_Kleene_1, Kleene closure - simplest case)
    std::string regex = "a*";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'a'}, {3},
        {
            {{final_project::automata::EPSILON, {1,3}}},
            {{'a', {2}}},
            {{final_project::automata::EPSILON, {1,3}}}
        }
    };
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    std::cout << str_out.str();
    std::cout << expected_out.str();
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

BEGIN_TEST(NFA_Generator_Kleene_2, This test tests if the NFA generator can handle the Kleene operator and concatentation together)
    std::string regex = "(ab)*";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
END_TEST()

BEGIN_TEST(NFA_Generator_Kleene_3, Kleene closure with alternation operator)
    std::string regex = "(a|b)*";
END_TEST()

BEGIN_TEST(NFA_Generator_Escape_1, Escaped character - simplest case)
    std::string regex = "\\*";
    std::istringstream str_in(regex);
    regex_parser parser(str_in);
    auto parsed = parser.parse();
    nfa n = final_project::automata::build_nfa(parsed);
    nfa expected = {{'*'}, {1},
        {
            {{'*', {1}}}
        }
    };
    std::ostringstream str_out;
    std::ostringstream expected_out;
    str_out << n;
    expected_out << expected;
    std::cout << str_out.str();
    std::cout << expected_out.str();
    CONTENT_CHECK(expected_out.str(), str_out.str())
    PASS_OR_FAIL()
END_TEST()

TEST_MAIN()