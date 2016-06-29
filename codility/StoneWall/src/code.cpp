// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
#include <stack>

/** @brief function that redraws Manhattan skyline
 * 
 *  Function aims to draw a skyline indicated with elements of 
 *  input vector with minimum number of possiblerectangles.
 *  Input vector contains N integersin therange [1 .. 1000000000]
 *  with N being in the range [1 .. 100000]
 *
 *  @param H input vector of building heights
 *  @retun minimum number of rectangles to draw the skyline
 */
int solution(std::vector<int> &H) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vector
    unsigned int N = H.size();
    
    // keep heights is stack.
    std::stack<int> heights;
    
    // number of rectangles needed
    int no_of_rect = 0;
    
    // iterate through vector and perform 
    for (unsigned int index = 0; index < N; ++index)
    {
        int curr_height = H[index];

        // flag to see if we need to insert current value
        bool done = false;
        
        // compare top of stack with new height
        while (0 != heights.size())
        {
            // get top of the stack
            int top = heights.top();
            
            // comparewith the current height, if greater add to stack
            if (curr_height > top)
            {
                heights.push(curr_height);
                done = true;
                break;
            } 
            else if (curr_height == top)    // if equal, they may be represented with a single rectangele, do nothing
            {
                done = true;
                break;
            }
            else    // else remove the upper element and increase counter to draw it.
            {
                heights.pop();
                no_of_rect++;
            }            
        }
        
        if (false == done)
            heights.push(curr_height);   
    }
    
    // remaining heights will be represented by rectangles
    no_of_rect += heights.size();
 
    return no_of_rect;
}
