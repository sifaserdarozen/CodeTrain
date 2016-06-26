// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#define MAX_CROSSING_CARS 1000000000

#include <vector>

/** @brief function that returns the number of numbers divisible by K
 * 
 *  Function return the numberof numbers divisible by K in region [A .. B]
 *  Assume that A <= B and A,B are integers in range [0 .. 2000000000]
 *  K is an integer in the range [1 .. 2000000000]
 *  
 *  @param A start of region
 *  @param B end of region
 *  @param K will be divisor
 *  @retun the number of numbers divisible by K.
 */
int solution(int A, int B, int K) {
    // write your code in C++11 (g++ 4.8.2)
    
    // find number of numbers that is divisible by k upto and including B.
    // remember to include zero
    int no_divisible_till_B = B / K + 1;
    
    // find number of numbers that is divisible by k upto and discarding A
    int no_divisible_till_Am = 0;
    if (A > 0)
        no_divisible_till_Am = ((A-1) / K) + 1;
    
    // result will be difference of two calculated sums    
    return no_divisible_till_B - no_divisible_till_Am;
}
