#ifndef DFA_HH
#define DFA_HH 1

#include <vector>
#include <unordered_map>

#include "nfa.hh"

namespace final_project
{
    namespace automata
    {
        //A struct to represent an DFA
        template<typename _TokTp>
        struct dfa
        {
            typedef std::vector<std::unordered_map<_TokTp, state_t>> table_t;

            public:
                dfa(const std::vector<state_t>& accepting_states, table_t& transitions)
                    : _M_accepting_states(accepting_states), _M_transitions(transitions)
                {

                }

            private:
                std::vector<state_t> _M_accepting_states;
                table_t _M_transitions;
        };

        //Construct a DFA from the specified NFA using the powerset 
        //construction technique. If the NFA has N states, the 
        //returned DFA may have up to 2^N states. 
        //
        //@param n the NFA to construct from
        //@return a DFA equiavalent to the NFA
        dfa<char> powerset_construction(const nfa& n);
    } // namespace automata
    
} // namespace final_project

namespace std
{
    template<>
    struct hash<std::set<final_project::automata::state_t>>
    {
        size_t operator()(const std::set<final_project::automata::state_t>& s) const
        {
            std::hash<int> hasher;
            size_t seed = 0;
            for(const auto state: s)
            {
                seed ^= hasher(state) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
} // namespace std


#endif
