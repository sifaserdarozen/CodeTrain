// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <iostream>


/** @brief function returns the number of possible minumun abs sum of weighted values
 * 
 *  Function returns minimum possible absolute sumof weighted values. A has values
 *  in range [-100 .. 100] and A has length [0 .. 20000]
 * 
 *  @param A input vector
 *  @retun minumum abs sum of weighted values
 */
int solution(std::vector<int> &A)
{
    // get size of flanks
    unsigned int N = A.size();
    
    std::vector<int> histogram(101, 0);
    
    // fill histogram
    for (unsigned int i = 0; i < N; ++i)
        histogram[abs(A[i])] ++;
        
    int sum = 0;
    int i= 101;
    while (i > 0)
    {
        i--;
        int no = histogram[i];
        int total = no * i;
        
        if (0 == no)
            continue;

        while (total)
        {
            sum = std::abs(sum - i);   
            total -= i;
        }
    }
    
    return sum;
}