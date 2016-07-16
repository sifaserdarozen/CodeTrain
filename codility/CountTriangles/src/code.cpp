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


/** @brief function returns the number of possible triangles
 * 
 *  Function returns number of possible triangles that may be 
 *  obtained by using elements of a vector A. Elements of A, 
 *  A[i] is in the range [1 .. 1000000000] and length of
 *  vector A may be [0 .. 1000]
 * 
 *  @param A input vector
 *  @retun number of possible triangles
 */
int solution(std::vector<int> &A)
{
    // get size of flanks
    unsigned int N = A.size();
    
    // do a sanity check, if there are not 3 elements, 
    // there will be nothing to check
    if ( N < 3 )
        return 0;
        
    // sort array
    std::sort(A.begin(), A.end());
    
    int triangle_count = 0;
    // now check sorted array to count triangles
    // since array is sorted, triangle may be obtained
    // if A[i] + A[j] > A[k], where k > j > i
    for(unsigned int i = 0; i < (N -2); ++i)
    {
        unsigned int k = (i + 2);
        for( unsigned int j = (i+1); j < (N-1); ++j)
        {
            triangle_count += k - j -1;
            for (; k < N; ++k)
                if ((A[i] + A[j]) > A[k])
                    triangle_count ++;
                else
                    break; 
        }
    }
    
    return triangle_count;
}