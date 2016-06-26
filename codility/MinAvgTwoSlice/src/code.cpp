// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <climits>

/** @brief function returns minimum average of any slice
 * 
 *  Let two indices P, Q define a slice so that 0 <= P < Q < N
 *  where N is size of input vector A. Therefore slice is 2 elements minimum.
 *
 *  Where each element of vector A is in region [-10000 .. 10000]
 *  and N is [2 .. 100000]
 *  
 *  @param A input vector
 *  @retun starting point of slice whose average is minimum.
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    unsigned int N = A.size();
    
    int minimum = INT_MAX;
    unsigned int minimum_pos = 0;
    
    // iterate through array to calculate double and tripplet accumulation and
    // update minimum value and index if necessary
    for (unsigned int index = 0; index < (N - 2); ++index)
    {
        int double_sum = A[index] + A[index +1];
        int tripple_sum = double_sum + A[index+2]; 
        
        if ((3*double_sum) < minimum)
        {
            minimum = 3*double_sum;
            minimum_pos = index;
        }
        if ((2*tripple_sum) < minimum)
        {
            minimum = 2*tripple_sum;
            minimum_pos = index;
        }
    }
    
    // check the last double which is missing due to (index < N -2)
    int double_sum = A[N-2] + A[N-1];
    if ((double_sum*3) < minimum)
        minimum_pos = N-2;
    
    return minimum_pos;
}
