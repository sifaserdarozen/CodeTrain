// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <iostream>

#define MAX_INTERSECTIONS 10000000

struct Circle
{
    unsigned int m_x;
    int m_r;
    Circle(): m_x(0), m_r(0) {}
    Circle(unsigned int x, int r): m_x(x), m_r(r) {}
    bool operator < (const Circle& rh) const {return m_r < rh.m_r;}
};

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
    int N = A.size();
    
    std::vector<Circle> Ac(N);
   
    // put elements of vactor to struct type
    for (unsigned int index = 0; index < N; ++index)
        Ac[index] = Circle(index, A[index]);
    
    // sort input vector
    std::sort(Ac.begin(), Ac.end());
      
    int intersections = 0;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        int x = Ac[N -1 -index].m_x;
        int r = Ac[N -1 - index].m_r;
        
        int lb = std::max(0, (x-2*r));
        int la = std::max(0, x-r);
        int ha = std::min((N-1), x+r);
        int hb = std::min((N-1), x+2*r);
        
        for (int ii = lb; ii < la; ++ii)
            if ((A[ii] <= r) && (A[ii] >= (x - r -ii)))
                intersections ++;

        for (int ii = la; ii < (x); ++ii)
            if (A[ii] <= r)
                intersections ++;

        for (int ii = (x+1); ii <= ha; ++ii)
            if (A[ii] < r)
                intersections ++;

        for (int ii = (ha + 1); ii <= hb; ++ii)
            if ((A[ii] < r) && (A[ii] >= ii -x -r))
                intersections ++;           
    }
    
    if (intersections > MAX_INTERSECTIONS)
        return -1;
    else
        return intersections;
}
