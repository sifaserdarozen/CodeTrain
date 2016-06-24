// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

/** @brief function returning missing permutation in a vector
 * 
 *  Function that return the the missing permutation in a vector.
 *  Assume N is choosen in the range [0 .. 100000]. Then all permutations
 *  of N will form N+1 size vector with elements 1, 2, 3, ... N+1
 *  However, we have a vector A sized N with one element missing. 
 *  Find the missing one in unsorted vector A.
 *  Here the property x^x = 0 is used to find the missing element.
 *  Notice that (x^y^z)^(x^z) = y
 *  
 *  @param A input vector of integers
 *  @retun missing permutation
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int N = A.size();
    
    // calculate cummulative xors of numbers 1 to N+1
    int cum_sum = 0;
    for(unsigned int index = 1; index <= (N + 1); ++index)
        cum_sum ^= index;
        
    // calculate cummulative xors with elements of the vector A
    for(unsigned int index = 0; index < N; ++index)
        cum_sum ^= A[index];
    
    return cum_sum;
}
