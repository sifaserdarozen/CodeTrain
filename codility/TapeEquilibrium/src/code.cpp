// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <limits>
#include <vector>
#include <cmath>    // for std::abs()

/** @brief function returning minimum absolute difference of cumulations
 * 
 *  Function that return the the minimum number of absolute differences
 *  of cummulative sums. For a vector A of size N, this is point P that minimizes
 *  |A[0] + A[1] + .. + A[P - 1] - A[P] - A[P + 1] - .. - A[N-1]|
 *  Assume that 0 < P < N,
 *  N is an integer between [2 .. 100000] and elements of A is between [-1000 .. 1000]
 *  
 *  @param A input vector of integers
 *  @retun minimum number of minimum absolute diffrence
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int N = A.size();
    
    // calculate cummulative sum of all elements
    int cum_sum = 0;
    for(unsigned int index = 0; index < N; ++index)
        cum_sum += A[index];
        
    // get the point that divides vector to find
    // minimum absolute difference of partition sums
    int cur_sum = 0;
    int min_difference = std::numeric_limits<int>::max();
    for (unsigned int index = 0; index < (N-1); ++index)
    {
        cur_sum += A[index];
        cum_sum -= A[index];
        
        int cur_difference = std::abs(cur_sum - cum_sum);
        
        if (cur_difference < min_difference)
            min_difference = cur_difference;
    }
    
    return min_difference;
}
