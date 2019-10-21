// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <cmath>
#include <stack>
#include <iostream>

/** @brief function returns the minimum perimeter of a rectangle
 * 
 *  Function tries to get minimum possible perimeter of a rectangle with
 *  given area. The sides of rectangle is assumed to be integers.
 *  N may vary between [1 .. 1000000000]
 *  
 *  @param N area of rectangleof concern
 *  @retun minimum possible perimeter conforming the area constraint
 */
int solution(int N) {
    std::stack<int> divisors;
    
    for (unsigned int i = 1; i <= sqrt(N); ++i) {
        if (0 == (N % i)) {
            divisors.push(i);
        }
    }    
            
    return 2*(divisors.top() + (N / divisors.top())); 
}
