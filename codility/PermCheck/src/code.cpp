// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <set>

/** @brief function returning weather an input vector is permutation or not
 * 
 *  Function that checks A's being permutation. 
 *  That means, if A is of length N such that N is [1 .. 100000], 
 *  and each element of A may be in [1 .. 1000000000],
 *  then A is said to be permutation if A contains all series between
 *  1, 2, 3, ... , N  possibly in out of order
 *  
 *  @param A input vector of integers
 *  @retun 1 or 0 indicating A's being permutation or not correspondingly.
 */
int solution(std::vector<int> &A){
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int N = A.size();
    
    // unique members set
    std::set<int> unique_members;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        if (A[index] <= N) {
            unique_members.insert(A[index]);
        }    
    }            
    
    return ((N == unique_members.size()) ? 1: 0);
}
