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

struct Node
{
    int m_position;
    int m_hops;
    Node(int position = 0, int hops = INT_MAX): m_position(position), m_hops(hops) {}
};


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
    std::vector<int> fibonacci_vector;
    int back_2 = 0;
    int back_1 = 1;
    int new_element = back_2 + back_1;
    while(new_element <= target_distance)
    {
        fibonacci_vector.push_back(new_element);
        back_2 = back_1;
        back_1 = new_element;
        new_element = back_2 + back_1;
    }
    
    // we have 1 or 0's at A[i] and if it is 0 thisplace is not reacable.
    // If it is 1, findminimum number of ways to reach this place recursively
    std::vector<Node> minimum_ways;
    std::vector<int> minimum_ways_vector(N + 1);
    
    for (unsigned int i = 0; i < N; ++i)
    {
        minimum_ways_vector[i] = 0;
        if (0 != A[i])
            minimum_ways.push_back(Node(i, INT_MAX));
    }

    minimum_ways.push_back(Node(N, INT_MAX));

    for(unsigned int i = 0; i < minimum_ways.size(); ++i)
    {
        int position = minimum_ways[i].m_position + 1;        
        int minimum_steps = INT_MAX;
        
        // now search recursively if we are able to reach indirectly
        for(unsigned int i_in = 0; i_in < fibonacci_vector.size(); ++i_in)
        {
            int fibonacci_distance = fibonacci_vector[i_in];
            //std::cout << "fibonacci distance: " << fibonacci_distance << " position: " << position << std::endl;
            if (position < fibonacci_distance)
                break;
            else if (position == fibonacci_distance)
            {
                minimum_steps = 1;
                break;   
            }
            else
            {
                int target_position = position - fibonacci_distance - 1;
                //std::cout << "-- target_position " << target_position << " " << minimum_ways_vector[target_position] << std::endl;
                if (0 != minimum_ways_vector[target_position])
                {
                    minimum_steps = std::min(minimum_steps, minimum_ways_vector[target_position] + 1);
                    
                }
            }
        }
            
        minimum_ways[i].m_hops = minimum_steps;
        minimum_ways_vector[position -1] = ((INT_MAX == minimum_steps)? 0: minimum_steps);
    }
    
    /*
    // Display reacability of leaves
    for(unsigned )
        std::cout << it->first << ":" << it->second << " ";
    std::cout << std::endl;
    */
  
    int distance = minimum_ways.back().m_hops;
  
    return (INT_MAX != distance)? distance: -1;    
}