// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <iostream>


/** @brief function returns the number of possible abs sum of pairs
 * 
 *  Function returns minimum possible absolute value sum abs(A[i] + A[j])
 *  where 0 <=i,j<N, N is between [1 .. 100000]
 *  and each element of A, A[i] will be between [-1000000000 ... 1000000000]
 * 
 *  @param A input vector
 *  @retun number of possible absolute sum of pairs
 */
int solution(std::vector<int> &A)
{
    // get size of flanks
    unsigned int N = A.size();
    
    // sort the vector, complexity will be N*log(N)
    std::sort(A.begin(), A.end());
    
    int min_abs = INT_MAX;
    
    unsigned int j = N-1;
    for (unsigned int i = 0; i < N; ++i)
    {
        int local_min = (std::abs(A[i] + A[j]));
        while(j > i)
        {
            if (std::abs(A[i] + A[j-1]) <= local_min)
            {
                local_min = (std::abs(A[i] + A[j-1]));
                j--;
            }
            else
                break;
        }
        min_abs = std::min(min_abs, local_min);
    }
    
    return min_abs;
}