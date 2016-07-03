// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <iostream>

#define MAX_INTERSECTIONS 10000000

long long int CombinationOfTwo(int n)
{
    if ( n < 2)
        return 0;
    return ((long long int)n * (n - 1)) / 2;
}

/** @brief function returns number of disc intersections
 * 
 *  Input vector contains N integers. A[k] is the radius ofthedisc positioned at k.
 *  Fucntion returns the numberof crossing discs. two discs A[i] and A[j] 
 *  intersects if i != k and |i-k| <= (A[i] + A[j])
 *  
 *  @param A input vector of integers
 *  @retun number of disc intersections
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of array to avoid multiple size get
    unsigned int N = A.size();
    
    // do a sanity check
    if (N < 2)
        return 0;
    
    std::vector<int> circle_starts(N);
    std::vector<int> circle_ends(N);
    
    // initialize vectors with zero
    for (unsigned int i = 0; i < N; ++i)
    {
        circle_starts[i] = 0;
        circle_ends[i] = 0;
    }
    
    // now iterate through vector A to find number of circle starts and ends at each index
    for (unsigned int i = 0; i < N; ++i)
    {
        int r = A[i];
        
        int start_point = std::max(0, ((int)i - r));
        int end_point = std::min((N-1), (i + (unsigned int)r));
        
        circle_starts[start_point] ++;
        circle_ends[end_point] ++;
    }
    
    int active_circles = circle_starts[0] - circle_ends[0];    // for A[0] = 0
    long long int intersections = CombinationOfTwo(active_circles);
    for (unsigned int i = 1; i < N; ++i)
    {
        intersections += ((active_circles * circle_starts[i]) + CombinationOfTwo(circle_starts[i]));
        active_circles += circle_starts[i];
        active_circles -= circle_ends[i];
    }
    
    if (intersections > MAX_INTERSECTIONS)
        return -1;
    else
        return intersections;
}
