// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

/** @brief function returning unpaired number in a vector
 * 
 *  Function that return the unpaired number in a vector
 *  Each element of vector is in range [1 .. 1000000000]
 *  Size of vector may be odd in range [1 .. 1000000]
 *  
 *  @param A input vector reference
 *  @retun unpaired number in the array
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vector
    unsigned int N = A.size();
    
    // do a sanity check. if size is 1, just return the only resident value
    if ( 1 == N )
        return A[0];
    
    // a fast algoritm may be using xor's
    // see that x^x is actually 0, and if we do an accumulating xor in the input vector
    // the result will be the only odd number of the vector
    int cummulative_xor = A[0];
    for (unsigned int index = 1; index < A.size(); ++index)
        cummulative_xor ^= A[index];
    
    return cummulative_xor;   
}
