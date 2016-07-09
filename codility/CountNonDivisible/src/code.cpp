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
        for (unsigned int k = i*i; k <= (unsigned int)maximum; k = k + i)
            if (0 == primes[k])
                primes[k] = i;
    }
    
    // allocate a vector to count divisors of vector elements
    std::vector<int> no_of_non_divisors(2*N + 1);
    
    for (unsigned int i = 0; i <= 2*N; ++i)
    {
       // std::cout << "-----------------------" << i << std::endl;
        int number_of_divisors = 0;
        if (0!=occurances[i])
        {
            std::set<int> local_divisors;
            local_divisors.insert(1);
            local_divisors.insert(i);
            for (unsigned int ii = 2; (ii*ii) <= i; ++ii)
            {
                //std::cout << " ** " << ii << std::endl;
                if (0 == i % ii)
                {
                    local_divisors.insert(ii);
                    local_divisors.insert(i/ii);
                }
            }
            // now count the number of divisors

            for (std::set<int>::iterator it = local_divisors.begin(); it != local_divisors.end(); it++)
            {
               // std::cout << "----" << *it << " " << occurances[*it] << std::endl;
                number_of_divisors += occurances[*it];
            }
        }    
        
        no_of_non_divisors[i] = N-number_of_divisors;        
    }

    std::vector<int> result(N);
    for (unsigned int i = 0; i < N; ++i)
    {
        result[i] = no_of_non_divisors[A[i]];
    }

    return result;
}
