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


/** @brief function returns the number ways that a ladder may be climbed
 * 
 *  Function requires number of ways a ladder may be climbed.
 *  L is the size of the vector that is in range [1 .. 30000]
 *  
 *  @param A vector indicating leaf presence
 *  @retun minimum number of jumps to cross the river
 */
int solution(std::vector<int> &A)
{
    // get size of array A
    unsigned int N = A.size();
    int target_distance = N + 1;
    
    // find fibonacci sequence up to N+1, the distance of pool
    // from one end to another
    std::set<int> fibonacci;
    fibonacci.insert(0);
    int back_2 = 0;
    int back_1 = 1;
    int new_element = back_2 + back_1;
    while(new_element <= target_distance)
    {
        fibonacci.insert(new_element);
        back_2 = back_1;
        back_1 = new_element;
        new_element = back_2 + back_1;
    }
    
    // we have 1 or 0's at A[i] and if it is 0 thisplace is not reacable.
    // If it is 1, findminimum number of ways to reach this place recursively
    std::map<int, int> minimum_ways;
    
    for (unsigned int i = 0; i < N; ++i)
        if (0 != A[i])
            minimum_ways[i] = INT_MAX;
    minimum_ways[N] = INT_MAX;

    for(std::map<int, int>::iterator it = minimum_ways.begin(); it != minimum_ways.end(); it++)
    {
        int position = it->first + 1;
        
        // if we are able to to jump with a single step from river edge, assign 1 
        // and skip search for indirect reachability
        const std::set<int>::iterator set_iterator = fibonacci.find(position);
        if (fibonacci.end() != set_iterator)
        {
            it->second = 1;
            continue;
        }
        
        int minimum_steps = INT_MAX;
        
        // now search recursively if we are able to reach indirectly
        for(std::map<int, int>::iterator it_in = minimum_ways.begin(); it_in != it; it_in++)
        {
            int position_in = it_in->first + 1;
            int value_in  = it_in->second; 
            // if the previous spot is not reacable, continue
            if ((INT_MAX == value_in) || ((value_in + 1) >= minimum_steps))
                continue;
            
            // then since this previous spot is reachable by value_in steps, 
            // search if we are able to reach this place through fibonacci
            const std::set<int>::iterator set_iterator = fibonacci.find(position - position_in);
            if (fibonacci.end() != set_iterator)
                minimum_steps = std::min(minimum_steps, value_in + 1);
        }
            
        it->second = minimum_steps;    
    }
    
    /*
    // Display reacability of leaves
    for(std::map<int, int>::iterator it = minimum_ways.begin(); it != minimum_ways.end(); it++)
        std::cout << it->first << ":" << it->second << " ";
    std::cout << std::endl;
    */
  
    int distance = minimum_ways[N];
  
    return (INT_MAX != distance)? distance: -1;    
}
