// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <iostream>

/** @brief function returning greatest common divisor
 *
 *  Greatest common divisor is found using modulus operator
 *
 *  @param A number 1
 *  @param B number 2
 *  @return greatest common divisor of A and B
 */
int GCD(int A, int B)
{
   int bigger = std::max(A, B);
   int smaller = std::min(A, B);
   int remainder = bigger % smaller;
   
    if ( 0 == remainder)
        return smaller;
    else
        return GCD(smaller, remainder);
}    

/** @brief function returns the number of common prime divisors
 * 
 *  A and B are two arrays containing integers in the range
 *  []. Function returns number of entries that have same common 
 *  divisors. As an example if A[i] = 12 and B[i] = 18, they are
 *  said to be having same prime divisors, since 12 = 2*2*3 and 
 *  18 = 2*3*3 and they both have 2 & 3 as prime divisors.
 *  Arrays have Z integers [1 .. 6000] in the range
 *  [1 .. 2147483647]
 *  
 *  @param A first vector
 *  @param B second vector
 *  @retun number of entries that have same prime divisors
 */
int solution(std::vector<int> &A, std::vector<int> &B)
{
    // get size of arrays, Z
    unsigned int Z = A.size();

 
    // number of common primes
    int no_of_common_primes = 0;
    
    for (unsigned int i = 0; i < Z; ++i)
    {
        // get greatest common divisor)
        int gcd_master = GCD(A[i], B[i]);
      
    
        int gcd = gcd_master;
        int num = A[i];
        
        while ((num > gcd) && (1 != gcd))
        {
            num = num / gcd;   
            gcd = GCD(num, gcd);
        }
        
        if ((1 == gcd) && (1 != num))
            continue;
            
        gcd = gcd_master;
        num = B[i];
        
        while ((num > gcd) && (1 != gcd))
        {
            num = num / gcd;   
            gcd = GCD(num, gcd);
        }
        
        if ((1 == gcd) && (1 != num))
            continue;
        
        no_of_common_primes ++;
    
    }
  
    return no_of_common_primes;    
}
