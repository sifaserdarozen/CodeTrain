// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <set>

/** @brief function minimum missing integer
 * 
 *  Function that returns the minimum missing integer
 *  Size of A is in range [1 .. 100000] where 
 *  each element is in the range [−2,147,483,648..2,147,483,647].
 *  Function puts positive elements in set, then checks the
 *  presence of integers in a loop.
 *  
 *  @param A input vector of integers
 *  @retun the minimum missing integer greater than zero.
 */
int solution(std::vector<int> &A){
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int N = A.size();
    
    // unique members set
    std::set<int> unique_positive_members;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        if (A[index] > 0)
            unique_positive_members.insert(A[index]);
    }
    
    int k = 1;
    for (std::set<int>::iterator it = unique_positive_members.begin(); it != unique_positive_members.end(); it++)
    {
        if (*it != k)
            return k;
        k++;
    }            
    
    return k;
}
