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


/** @brief function returns number of possible non overlapping segments
 * 
 *  Function returns maximum possible non overlapping segments. A and B
 *  are vectors said to be length [0 .. 30000], indicating start and end of
 *  segments with elements of B are nondegreasing order.
 *  Each elements of start and end may be in the range [0 .. 1000000000]
 * 
 *  @param A input vector indicating start of segments
 *  @param B input vector indicating end of segments
 *  @retun number of possible non overlapping segments
 */
int solution(std::vector<int> &A, std::vector<int> &B)
{
    // get size of flanks
    unsigned int N = A.size();
    
    int number_of_segments = 0;
    int end_of_last_segment = -1;

    for (unsigned int i = 0; i < N; ++i)
    {
        if (A[i] > end_of_last_segment)
        {
            number_of_segments ++;
            end_of_last_segment = B[i];
        }
    }
    
    return number_of_segments;
}