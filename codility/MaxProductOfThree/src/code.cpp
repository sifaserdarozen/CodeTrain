// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <climits>    // for INT_MIN

/** @brief function returns maximum possible triplet product
 * 
 *  Find the maximum of any triplet product of elements in vector A such that
 *  Let A contains N unsorted integers where N is in the range [3 .. 100000]
 *  and each number in A is from set [−1000 .. 1000]
 *  
 *  @param A input vector of integers
 *  @retun maximumpossible product
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of array to avoid multiple size get
    unsigned int N = A.size();
    
    // sort input vector
    std::sort(A.begin(), A.end());
    
    int max_product = INT_MIN;
    
    // loop through first three and last three members in the array
    max_product = std::max(max_product, A[0]*A[1]*A[2]);
    max_product = std::max(max_product, A[0]*A[1]*A[N-1]);
    max_product = std::max(max_product, A[0]*A[N-2]*A[N-1]);
    max_product = std::max(max_product, A[N-3]*A[N-2]*A[N-1]);

    return max_product;
}
