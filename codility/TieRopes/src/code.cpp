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


/** @brief function returns numberof rope segments that have length K
 * 
 *  Function returns maximum possible rope segments that exceed length K
 *  after joining adjacent segments.
 * 
 *  @param K length threshold that must be satisfied
 *  @param A input vector
 *  @retun number of possible segments satisfying length condition
 */
int solution(int K, std::vector<int> &A)
{
    // get size of flanks
    unsigned int N = A.size();
    
    int number_of_segments = 0;
    int local_sum = 0;
    for(unsigned int i = 0; i < N; ++i)
    {
        local_sum += A[i];
        if (local_sum >= K)
        {
            number_of_segments ++;
            local_sum = 0;
        }
    }
    return number_of_segments;
}