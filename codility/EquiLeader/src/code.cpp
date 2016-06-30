// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
#include <stack>

/** @brief function counts number of division points
 * 
 *  Function aims to find number of division points of vector A
 *  having elements [-1000000000 .. 1000000000] with size N 
 *  being in the range [1 .. 100000].
 *  Division point S should be such that A[0]..A[s] and A[S+1] .. H[N-1]
 *  should both have same leader.
 *  A leader is defined to be number occuring more than half of the 
 *  members in this special cae
 *
 *  @param A input vector of numbers
 *  @retun number of possible division points
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of vector
    unsigned int N = A.size();
   
    // do a sanity check. if N < 2, return 0
    if (N < 2)
        return 0;
    
    // use stack to find more than half occuring number
    std::stack<int> max_num;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        if (0 == max_num.size())
        {
            max_num.push(A[index]);
            continue;
        }
    
        if (max_num.top() == A[index])
            max_num.push(A[index]);
        else
            max_num.pop();
    }
    
    if (0 == max_num.size())    // check if there is a dominant number or not
        return 0;
        
    int dominant_number = max_num.top();    // get the dominant number
    
    // count occurance of dominant number
    int max_count = 0;
    for (unsigned int index = 0; index < N; ++index)
        if (dominant_number == A[index])
            max_count ++;
         
    // calculate number of disection points         
    int no_of_points = 0;
    int curr_count = 0;
    for (unsigned int index = 0; index < N; ++index)
    {
        if (dominant_number == A[index])
        {
            curr_count ++;
            max_count --;
        }
        if (((2*curr_count) > (index+1)) && ((2*(max_count)) > (N-index-1)))
            no_of_points ++;
    }            
    
    return no_of_points;
}
