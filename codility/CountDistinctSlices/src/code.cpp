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

#define MAX_SLICE_COUNT 1000000000    //<! maximum slice count

/** @brief function returns the number of distinct slices
 * 
 *  Function returns number of distinct slices. Ocuurance of elements
 *  are kept in a vector, to update possible slices when a repetition
 *  occurs.
 *  
 *  @param M maximum value elements of array A may take
 *  @param A input non negative vector
 *  @retun number of distinct slices
 */
int solution(int M, std::vector<int> &A)
{
    // get size of flanks
    int N = A.size();
    
    // keep occurance of elements in a vector
    std::vector<int> last_occurances(M + 1);
    for (int i = 0 ; i <=M; ++i)
        last_occurances[i] = -1;
    
    long long int slice_count = 0;
    
    int last_checked = 0;
    
    for (int i = 1 ; i <= N; ++i)
    {
        int target = A[i-1];
              
        // see when this number last occured, if occured after a checkpoint,
        // then this means a repetition, and elements up to first occurance
        // should form slices and added to gross sum. Else, the occurance will be updated
        if ( last_checked < last_occurances[target])
        {
            // see how many elements should be reseted
            int no_of_items = last_occurances[target] - last_checked;
            
            // see how many iterations shoulw we make
            int no_of_iter = i - last_checked - 1;
            
            // calculate slice possibilities
            slice_count += (((long long int)no_of_iter * (no_of_iter + 1)) / 2) - 
                            (((long long int)(no_of_iter - no_of_items)*(no_of_iter - no_of_items + 1)) / 2);
        
            last_checked = last_occurances[target];
        }
        last_occurances[target] = i;
    }
    
    // do remaining items
                // see how many elements should be reseted
    int no_of_items = N - last_checked;
            
    // see how many iterations shoulw we make
    int no_of_iter = N - last_checked;
            
    // calculate slice possibilities
    slice_count += (((long long int)no_of_iter * (no_of_iter + 1)) / 2) - 
                           (((long long int)(no_of_iter - no_of_items)*(no_of_iter - no_of_items + 1)) / 2);
    
    // check to see if we need overflow
    if (slice_count > MAX_SLICE_COUNT)
        slice_count = MAX_SLICE_COUNT;
    
    return slice_count;
}