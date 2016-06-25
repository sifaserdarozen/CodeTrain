// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <set>

/** @brief function that returns state of counters
 * 
 *  Function that returns the state of N counters that are changed due to
 *  if A[k] = x, if x is in range, 1 <= x <= N, increment counter x by one
 *  else if A[k] = x, and x = N+1, set all counters to biggest one
 *  
 *  @param A input vector of integers
 *  @retun the minimum missing integer greater than zero.
 */
std::vector<int> solution(int N, std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int size_of_A = A.size();
    
    int current_maximum = 0;
    int current_base = 0;
    
    // unique members set
    std::vector<int> states(N);
    
    for (unsigned int index = 0; index < size_of_A; ++index)
    {
        int curr_index = A[index];
        if ( curr_index > N )
            current_base = current_maximum;
        else
        {
            int curr_val = states[curr_index-1];
            curr_val = std::max(curr_val, current_base);
            curr_val ++;
            current_maximum = std::max(curr_val, current_maximum);
            states[curr_index -1] = curr_val;
        }
    }
        
    for (unsigned int index = 0; index < N; ++index)
        states[index] = std::max(current_base, states[index]);
         
    return states;
}
