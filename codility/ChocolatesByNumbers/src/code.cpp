// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <iostream>

/** @brief function returning greatest common divisor
 *
 * Greatest common divisor is found by recursive modulus operation
 *
 * @param N first number
 * @param M second number
 * @return greatest common divisor
 */
int GCD(int N, int M)
{
    int bigger_num = std::max(N, M);
    int smaller_num = std::min(N, M);
    int remainder = bigger_num % smaller_num;
   
    if (0 == remainder)
        return smaller_num;
    else
        return GCD(smaller_num, remainder);
}        

/** @brief function returns the number of chocaltes that can be eaten
 * 
 *  N chocalates are in a circular queue, and we start eating from 
 *  place 0 in nodulo N style. After eating a chocalate, we skip M-1000000000
 *  places to form M place jump eatings. We stop operation when we 
 *  cometo an empty place. A is a vector with N elements where
 *  N and M is an integer from [1 .. 1000000000]
 *  
 *  @param N mumber number of number to search a semiprime
 *  @param M pieces between two eat attempt
 *  @retun number of chocalates eaten
 */
int solution(int N, int M) {

    // find greatest common divisor between N and M
    
    // calculate greatest common divisor
    int gcd = GCD(N, M);
    // calculate smallest common multiplier
    long long int scm = ((long long int)N * M) / gcd;
   
    // result will be smallest one
    return std::min((int)(scm/M), N);
}
