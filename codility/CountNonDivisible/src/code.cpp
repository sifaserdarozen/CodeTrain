// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <set>
#include <climits>
#include <iostream>

/** @brief function returns the number elements of that are not divisible
 * 
 *  Function returns the number of elements in an array that are 
 *  not divisors. A is a vector with N elements where
 *  N is an integer from [1 .. 50000] and each element in the array
 *  A[i] are in the range [1 .. 2*N]
 *  
 *  @param A mumber number of number to search a semiprime
 *  @retun number of possible slices
 */
std::vector<int> solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    unsigned int N = A.size();
    
    // allocate a vector to count occurances of vector elements
    std::vector<int> occurances(2*N + 1);
    
    // initialize to zero
    for (unsigned int i = 0; i <= 2*N; ++i)
        occurances[i] = 0;
        
    // now count elements in the array with finding maximum
    int maximum = INT_MIN;
    for (unsigned int i = 0; i < N; ++i)
    {
        maximum = std::max(maximum, A[i]);
        occurances[A[i]] ++;
    }
    
    // Now find prime divisors up to maximum
    std::vector<int> primes(maximum+1);
    // initialize to zero
    for (unsigned int i = 0; i <= (unsigned int)maximum; ++i)
        primes[i] = 0;
        
    // find primes
    for (unsigned int i = 2; i <= (unsigned int)maximum; ++i)
    {
        if (0 != primes[i])
            continue;
        for (unsigned int k = i*i; k <= (unsigned int)maximum; ++k)
            if (0 == primes[k])
                primes[k] = i;
    }

    // since we now have primes and counts, we may calculate
    // occurances of non divisors
    std::vector<int> result(N);
    for (unsigned int i = 0; i < N; ++i)
    {
        int target = A[i];
        std::set<int> used_primes;
        
        int divisors = occurances[target];
        used_primes.insert(target);
        unsigned int past_set_size = 1;
        
        used_primes.insert(1);
        if (past_set_size != used_primes.size())
        {
            divisors += occurances[1];
            past_set_size++;
        }

        int smallest_prime = primes[target];
        while ((0 != smallest_prime) && ((smallest_prime*smallest_prime) <= A[i]))
        {
            used_primes.insert(smallest_prime);
            if (past_set_size != used_primes.size())
            {
                divisors += occurances[smallest_prime];
                past_set_size++;
            }
            
            target = A[i] / smallest_prime;
            used_primes.insert(target);
            if (past_set_size != used_primes.size())
            {
                divisors += occurances[target];
                past_set_size++;
            }
 
            smallest_prime = primes[target];        
        }

        result[i] = N - divisors;
    }
    
    return result;
}
