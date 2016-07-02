// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

/** @brief function returns maximum sum of a slice
 * 
 *  Calculate the sum of slice between two points P & Q
 *  such that 0 <= P <= Q < N, and sum is A[P] + .. + A[Q]
 *  assume that N is [1 .. 1000000]
 *  and each element is between [-1000000 .. 1000000]
 *  and maximum is in the range  [−2147483648 .. 2147483647]
 *
 *  @param A input vector of numbers
 *  @retun maximum sum of any double slice
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of vector
    unsigned int N = A.size();
   
    int max_slice = A[0];
    int max_sum = A[0];
    for(unsigned int i = 1; i < N; ++i)
    {
        max_slice = std::max(A[i], max_slice+A[i]);
        max_sum = std::max(max_sum, max_slice);
    }
    
    return max_sum;  
}
