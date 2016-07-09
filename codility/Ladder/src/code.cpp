// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <iostream>


/** @brief function returns the number ways that a ladder may be climbed
 * 
 *  Function requires number of ways a ladder may be climbed.
 *  L is the size of the vector that is in range [1 .. 30000]
 *  
 *  @param A vector indicating ladder length
 *  @param B modulus vector that should be performed
 *  @retun resulting number of ways
 */
std::vector<int> solution(std::vector<int> &A, std::vector<int> &B)
{
    // get size of arrays, Z
    unsigned int L = A.size();

    std::vector<int> different_ways(L);
    
    // calculate fibonacci calculation in 2^31 modula 
    std::vector<unsigned int> fibonacci(L+1);
    fibonacci[1] = 1;
    fibonacci[2] = 2;
    for (unsigned int i = 3; i <= L; ++i)
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        
    for (unsigned int i = 0; i < L; ++i)
    {
        unsigned int modulus = ((1 << B[i])) - 1;
        different_ways[i] = fibonacci[A[i]] & modulus;
    }
  
    return different_ways;    
}
