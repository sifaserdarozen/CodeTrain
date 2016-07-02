// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>


/** @brief function returns maximum possible profit
 * 
 *  Input vector gives daily prices of a stock. Find the
 *  maximum possible gain by buying at time P, selling
 *  at time Q suct that 0 <= P <= Q < N
 *  assume that N is [0 .. 400000]
 *  and each element is between [0 .. 200000]
 *
 *  @param A input vector of numbers
 *  @retun maximum sum of any double slice
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of vector
    unsigned int N = A.size();
   
    // do a sanity check. if N < 2, return 0
    if ( N < 2 )
        return 0;
    
    int max_profit = 0;
    
    int min = A[0];
    for( unsigned int i = 0; i < N; ++i)
    {
        // update maximum profit if necessary
        max_profit = std::max(max_profit, (A[i] - min));
        // update minimum if necessary
        if (A[i] < min)
            min = A[i];
    }
    
 
    // maximum possible profit may not be negative
    if (max_profit < 0)
        return 0;
    
    return max_profit;  
}
