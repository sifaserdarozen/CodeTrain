// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <set>

/** @brief function returning time that frog is able to cross street
 * 
 *  Function that return the instant that frog is able to reach point X.
 *  X is an integer in the range [1 .. 100000]
 *  Vector A is the information about fallen leaves to pool. A[k] is the
 *  place there at time k a leaf falls. Frog is able to cross the pool as soon asctime
 *  leaves are fallen to 1, 2, ..., x positions
 *  
 *  @param X target point
 *  @param A input vector of integers
 *  @retun time that frog is able to cross
 */
int solution(int X, std::vector<int> &A){
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int N = A.size();
    
    // fallen leaves set
    std::set<int> fallen_leaves;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        if (A[index] <= X)
            fallen_leaves.insert(A[index]);
        if (X == fallen_leaves.size())
            return index;
    }            
    
    return -1;
}
