// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

/** @brief function performing circular shift of a vector
 * 
 *  Function circular shifts vector A to right with K points
 *  Sizeof vector and K may be in range [0 .. 100]
 *  Each element of vector is in range [-1000 .. 1000]
 *  
 *  @param A input vector reference
 *  @param K circular shift index
 */
std::vector<int> solution(std::vector<int> &A, int K) {
    // write your code in C++11 (g++ 4.8.2)
    
    // do sanity check, if size of array is zero or one, or K is less than 1, nothing to shift
    unsigned int N = A.size();
    if (( 1 >= N ) || ( 1 > K ))
        return A;
    
    // declere shifted vector
    std::vector<int> shifted_A(N);
    
    // loop through input vector to generate shifted version
    for (unsigned int index = 0; index < N; ++index)
    {
        unsigned int new_index = (index + K) % N;
        shifted_A[new_index] = A[index];
    }
     
    return shifted_A;   
}