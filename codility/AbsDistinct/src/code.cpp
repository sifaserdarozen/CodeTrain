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

/** @brief function returns the number of distinct absolute values
 * 
 *  Vector A is non decreasing having elements in the range 
 *  [−2147483648..2147483647] with possible length [1 .. 100000]
 *  
 *  @param A input non decreasing vector
 *  @retun number of distinct values
 */
int solution(std::vector<int> &A)
{
    // get size of flanks
    unsigned int N = A.size();
    
    // set that will keep the input vector
    std::set<int> abs_set;
    
    // put elements into set
    for(unsigned int i = 0; i < N; ++i)
        abs_set.insert(std::abs(A[i]));
        
    return abs_set.size();
}