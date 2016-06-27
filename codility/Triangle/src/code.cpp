// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // std::sort
#include <vector>

/** @brief function checks weather there is a triangle in a vector
 * 
 *  Let A contains N unsorted integers where N is in the range [0 .. 100000]
 *  and each number in A is from set [−2,147,483,648..2,147,483,647]
 *  
 *  @param A input vector of integers
 *  @retun If there are numbers forming triangle return 1, else return 0
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of array to avoid multiple size get
    unsigned int N = A.size();
    
    // do a sanity check, if N is less than 3, there will be no triangle at all
    if (N < 3)
        return 0;
    
    // let sort array so that closer numbers sit to gether
    // use default comparison operator with std::sort
    std::sort(A.begin(), A.end());
    
    // loop through sorted vector to see any triplet forms a triangle
    // with checking A[i] + A[i+1] > A[i+2]
    for (unsigned int index = 0; index < (N-2); ++index)
        if ((A[index] > 0) && (((long long int)(A[index]) + A[index+1]) > A[index+2]))
            return 1;
    
    return 0;
}
