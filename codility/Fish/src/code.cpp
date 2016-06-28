// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::sort()
#include <vector>
#include <iostream>
#include <climits>

/** @brief function returns number of surviving fish
 * 
 *  Input vector A contains sizes of the fish, and B contains
 *  their drection 0 downstrem amd 1 upstream.
 *  When two fish meet, the bigger one eats the smaller
 *  and continues its way.
 *  
 *  @param A input vector of sizes of fish
 *  @param B input vector of directions of fish
 *  @retun number of surviving fish
 */
int solution(std::vector<int> &A, std::vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of array to avoid multiple size get
    unsigned int N = A.size();
    
    // do a sanity check,if there isonly one fish, he will survive
    if (1 == N)
        return 1;
    
    int surviving_fish = 0;
    int max_size_going_downstream = INT_MIN;
    int max_size_going_upstream = INT_MIN;
    
    // calculate that will survive going upstream
    for (unsigned int index = 0; index < N; ++index)
    { 
        // count surviving fish that swims upstream
        if ((0 == B[index]) && (A[index] > max_size_going_downstream))
        {
            surviving_fish ++;
            max_size_going_downstream = INT_MIN;
        }
        else if ((1 == B[index]) && (A[index] > max_size_going_downstream))
        {
            max_size_going_downstream = A[index];
        }
        
        // count surviving fish that swim downstream
        unsigned int rev_index = N -1 -index;
        if ((1 == B[rev_index]) && (A[rev_index] > max_size_going_upstream))
        {
            surviving_fish ++;
            max_size_going_upstream = INT_MIN;
        }
        else if ((0 == B[rev_index]) && (A[rev_index] > max_size_going_upstream))
        {
            max_size_going_upstream = A[rev_index];
        }  
    }
    
    return surviving_fish;
}
