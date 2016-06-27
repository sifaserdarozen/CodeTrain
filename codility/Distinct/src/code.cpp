// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <set>
#include <vector>

/** @brief function returns number of distinct values in a vector
 * 
 *  Let A contains N unsorted integers where N is in the range [0 .. 100000]
 *  and each number in A is from set [−1000000 .. 1000000]
 *  
 *  @param A input vector of integers
 *  @retun the number of distinct values
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of array to avoid multiple size get
    unsigned int N = A.size();
    
    std::set<int> distinct_set;
    
    // loop through input vector to find add numbers to distinct set
    for (unsigned int index = 0; index < N; ++index)
        distinct_set.insert(A[index]);
    
    return distinct_set.size();
}
