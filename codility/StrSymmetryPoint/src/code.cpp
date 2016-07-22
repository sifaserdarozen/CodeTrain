// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <iostream>
#include <string>

/** @brief function returns the symmetry point in a string
 * 
 *  Function returns symmetry point of a string S, or
 *  -1 if there is not such a point.
 *  Length of S may be within the range [0 .. 2000000]
 * 
 *  @param S string to search symmetry
 *  @retun symmetry point of string or 
 */
int solution(std::string &S) {
    // write your code in C++11 (g++ 4.8.2)
    // do sanith checks
    unsigned int N = S.size();
    
    if (0 == N%2)
        return -1;
        
    if (1 == N)
        return 0;
        
    unsigned int i = 0;
    unsigned int j = N-1;
    while (i < j)
    {
        if (S[i] != S[j])
            return -1;
        i++;
        j--;
    }
    
    return i;
}