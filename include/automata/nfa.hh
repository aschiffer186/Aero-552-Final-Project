#ifndef NFA_HH
#define NFA_HH 1

#include <vector>
#include <unordered_map>
#include <ostream>
#include <set>

namespace final_project::automata
{
    //A state in the NFA
    typedef int state_t;
    //The epsilon character
    static const char EPSILON = '\0';

    //A simple struct to represent a non-deterministic finite automatum (NFA).
    //This struct contaions information about the NFA's accepting states and 
    //state transition table. 
    struct nfa
    {
        //The type of the state transition table
        typedef std::vector<std::unordered_map<char, std::vector<state_t>>> table_t;

        //Increments all states in the NFA by the specified number 
        //
        //@param delta the amount to increment the states by
        void renumber(state_t delta);

        //The NFA's alphabet
        std::set<char> _M_alphabet;
        //The NFA's accepting states
        std::vector<state_t> _M_accepting_states;
        //The NFA's state transition table
        table_t _M_transitions;
    };

    inline void nfa::renumber(state_t delta)
    {
        for(auto& state: _M_accepting_states)
            state += delta;
        for(auto& row: _M_transitions)
        {
            for(auto& transition: row)
            {
                for(auto& state: transition.second)
                    state += delta;
            }
        }
    }

    //Constructs an NFA using Thompson's construction that can recognize the
    //language defined by the union of the specified regular expressions. 
    //The regular expressions must be in postfix notation.
    //
    //@param regex the regular expressions to create an NFA for 
    //@return an NFA that can be used to recognize the regular expressions
    nfa build_nfa(const std::vector<std::vector<char>>& regex);
}

 std::ostream& operator<<(std::ostream& os, const final_project::automata::nfa& n);

#endif