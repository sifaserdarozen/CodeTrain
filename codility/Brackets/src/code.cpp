// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <stack>
#include <iostream>


/** @brief function that checks properly nesting of paranthesis
 * 
 *  Input string S contains characters from '{', '}', '[', ']', '(', ')'
 *  and S should be checked agains proper nesting. 
 *  Some property nested strings are
 *  "" --> empty string
 *  "{}"  --> basic pair
 *  "{[()]}"  --> nested paranthesis
 *  "{[]()}()"  --> sequence of nested paranthesis
 *
 *  @param S input string of characters
 *  @retun number of surviving fish
 */
int solution(std::string &S) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of array to avoid multiple size get
    std::stack<int> paranthesis;
    
    // get sizeof string
    unsigned int N = S.size();
    
    // iterate through S in order to match pairs
    for(unsigned int index = 0; index < N; ++index)
    {
        char ch = S[index];
        if (('{' == ch) || ('[' == ch) || ('(' == ch))
        {
            paranthesis.push(ch);
        }
        else if (('}' == ch) || (']' == ch) || (')' == ch))
        {
            if (0 == paranthesis.size())
                return 0;
            char top = paranthesis.top();          
            if  ((('}' == ch) && ('{' == top)) || ((']' == ch) && ('[' == top)) || ((')' == ch) && ('(' == top)))
                paranthesis.pop();
            else
                return 0;
        }
    }
    
    return ((0 == paranthesis.size())? 1: 0);
}
