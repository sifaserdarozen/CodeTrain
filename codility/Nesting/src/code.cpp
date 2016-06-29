// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>

/** @brief function that checks properly nesting of paranthesis
 * 
 *  Input string S contains characters from '(', ')'
 *  and S should be checked agains proper nesting. 
 *  Some property nested strings are
 *  "" --> empty string
 *  "()"  --> basic pair
 *  "((()))"  --> nested paranthesis
 *  "(()())()"  --> sequence of nested paranthesis
 *  Size of S may be in the range [0 .. 1000000]
 *
 *  @param S input string of characters
 *  @retun number of surviving fish
 */
int solution(std::string &S) {
    // write your code in C++11 (g++ 4.8.2)
    
    unsigned int counter = 0;
    
    // get sizeof string
    unsigned int N = S.size();
    
    // iterate through S in order to match pairs
    for(unsigned int index = 0; index < N; ++index)
    {
        char ch = S[index];
        if ('(' == ch)
            counter++;
        else if (')' == ch)
            if (counter > 0)
                counter--;
            else
                return 0;
    }
    
    return ((0 == counter)? 1: 0);
}
