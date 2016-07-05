// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <iostream>

/** @brief function returns the number of semi primes
 * 
 *  Function returns the number of semi primes starting at P[i]
 *  ending in Q[i], where 1 <= P[i] <= Q[i] <= N
 *  N is an integer from [1 .. 50000] and length of P & Q may be
 *  [1 .. 30000]
 *  
 *  @param N mumber number of number to search a semiprime
 *  @param P vector stating starting point of search
 *  @param Q vector stating end point of search
 *  @retun number of possible slices
 */
 
 
std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    
    std::vector<int> result;
    
    // do a sanity check
    if (N < 1)
        return result;
        
    unsigned int N_ui = (unsigned int) N;
    
    std::vector<int> primes(N_ui + 1);
    
    // set content to zero
    for (unsigned int i = 0; i <= N_ui; ++i)
        primes[i] = 0;
        
    // now primes and its smallest factor through sieve of eratosthenes
    for (unsigned int i = 2; i*i <= N_ui; ++i)
    {
        if (0 != primes[i])
            continue;
            
        // start from i*i
        unsigned int start_point = i*i;
        while (start_point <= N_ui)
        {
            if (0 == primes[start_point])
                primes[start_point] = i;
            start_point += i;
        }
    }
    
    std::vector<int> semi_primes(N_ui + 1);
    
    unsigned int total_semi_primes = 0;
    
    // notice that 2 and 3 is prime, so start from 4
    for (unsigned int i = 0; i <= N_ui; ++i)
    {
        if ((0 != primes[i]) && (0 == primes[(i/primes[i])]))
            total_semi_primes ++;
        semi_primes[i] = total_semi_primes;            
    }
    
    // now since we have prefix sum of subprime numbers
    // we may populate resulting array
    for (unsigned int i = 0; i < P.size(); ++i)
    {
        unsigned int start_index = 0;
        if (0 != P[i])
            start_index = P[i] - 1;
        
        result.push_back(semi_primes[Q[i]] - semi_primes[start_index]);        
    }
    
    /*
    for (unsigned int i = 0; i <= N_ui; ++i)
        std::cout << i << " " << semi_primes[i] << std::endl;
     */
    
        
    return result;
}
