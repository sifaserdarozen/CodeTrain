// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <iostream>

/** @brief function returns the number of factors of a number N
 * 
 *  Function tries to get number of factors of a number.
 *  Factors, Fi are perfect divisors of N that may be in range [1 .. N]
 *  such that N % Fi = 0
 *  N may vary between [1 .. 2147483647]
 *  
 *  @param N the number
 *  @retun number of factors of N
 */
int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
    
    // check factors up to sqrt(N), count twice in order to include D
    // as if N/F=D and N%F=0, so does N%D 
    int number_of_factors = 0;
    for (unsigned int i = 1; i <= sqrt(N); ++i)
        if (0 == (N % i))
            if (i != (N/i))
                number_of_factors += 2;
            else
                number_of_factors ++;
            
    return number_of_factors; 
}
