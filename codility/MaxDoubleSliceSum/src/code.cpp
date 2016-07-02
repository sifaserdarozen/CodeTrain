// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>


/** @brief function returns maximum sum of any double slice
 * 
 *  Double slice is defined by 3 numbers X, Y, Z such that
 *  0 <= X < Y < Z < N 
 *  and sum is calculated as;
 *  A[X+1] + .. + A[Y-1] + A[Y+1] + .. + A[Z-1]
 *  assume that N is [3 .. 100000]
 *  and each element is between [-10000 .. 10000]
 *
 *  @param A input vector of numbers
 *  @retun maximum sum of any double slice
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of vector
    unsigned int N = A.size();
   
    // do a sanity check. if N < 2, return 0
    if (3 == N)
        return 0;
    
    
    std::vector<int> first_slice_sum(N);
    std::vector<int> second_slice_sum(N);
    
    int first_slice = 0;
    first_slice_sum[1] = 0;  // since represents up to but not including i, 
    int second_slice = 0;
    second_slice_sum[N-2] = 0;  // since represents after than but not including i, 
    
    for (unsigned int i = 2; i < N-1; ++i)
    {   
        // past maximum sum is either sum of past values and current one
        // or zero, if the sum is zero. Remember that we can easly set start indextomake zero.        
        first_slice = std::max(0, (first_slice + A[i-1]));
        first_slice_sum[i] = first_slice;
        
        // future maximum sum is either sum of future values and current one
        // or zero, if the sum is zero. Remember that we can easly set start index to make zero.        
        second_slice = std::max(0, (second_slice + A[N-i]));
        second_slice_sum[N-1-i] = second_slice;
    }
    
    int max_sum = 0;
    for (unsigned int i = 1; i < N-1; ++i)
        max_sum = std::max((first_slice_sum[i] + second_slice_sum[i]), max_sum);    

    return max_sum;  
}
