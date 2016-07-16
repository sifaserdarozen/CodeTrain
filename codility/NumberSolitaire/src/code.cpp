// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <list>
#include <vector>
#include <climits>
#include <iostream>


/** @brief function returns the subset of maximal sum
 * 
 *  Function returns maximum possible sum of traversing an array A
 *  starting from A[0] to A[N-1] with steps 1 to 6 of your choice
 *  in order to achieve maximum possible sum.
 * 
 *  @param A input vector
 *  @retun subset of maximal sum
 */
int solution(std::vector<int> &A)
{
    // get size of flanks
    unsigned int N = A.size();
    
    std::list<int> past_costs = {A[0], A[0], A[0], A[0], A[0], A[0]};
 
    for (unsigned int i = 1; i < N; ++i)
    {
        int cost = INT_MIN;
        for (std::list<int>::iterator it = past_costs.begin(); it != past_costs.end(); it++)
            cost = std::max(cost, (*it + A[i]));
        past_costs.push_front(cost);
        past_costs.pop_back();
    }
    
    return past_costs.front();
}