// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <iostream>
#include <vector>

/** @brief function returns the maximum number of flags that can be placed to peaks
 * 
 *  Function returns number of maximum flags that can be places on peaks. Game rule
 *  includes requirement of spacing ach flag with the number of flags originally taken.
 *  If a mountaineer has taken K flags, any twoflags he has put on peaks should be
 *  seperated with this amount. A peak is an index that has 
 *  greater value from it's precessor and successor
 *  N may vary between [1 .. 400000] and each element in the range
 *  [0 .. 1000000000]
 *  
 *  @param A input vector of integers
 *  @retun number of possible slices
 */
int solution(std::vector<int>& A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of A
    unsigned int N = A.size();
    
    // count number_of_peaks;
    int no_of_peaks = 0;
    
    std::vector<unsigned int> previous_peak_location(N);
    unsigned int previous_peak = 0;
    previous_peak_location[0] = 0;
    
    std::vector<int> peaks_prefix_sum(N);
    peaks_prefix_sum[0] = 0;
  
    for (unsigned int i = 1; i < (N-1); ++i)
    {
        if ((A[i-1] < A[i]) && (A[i] > A[i+1]))
        {
            no_of_peaks ++;
            previous_peak = i;
        }
        peaks_prefix_sum[i] = no_of_peaks;
        previous_peak_location[i] = previous_peak;
    }
    
    peaks_prefix_sum[N-1] = no_of_peaks;
    previous_peak_location[N-1] = previous_peak;
    
    // do a sanity check. if there are no peaks, then
    // there will be no slice at allocate
    if (0 == no_of_peaks)
        return 0;

    unsigned int max_flags = 0;
    
    unsigned int flags_taken = no_of_peaks;
    while (flags_taken > 0)
    {
        unsigned int minimum_step = flags_taken;
    
        // check number of flags that may be put
        unsigned int no_of_flags = 0;
        unsigned int location_of_prev_peak = previous_peak_location[N-1];
        if (0 != location_of_prev_peak) {
            no_of_flags ++;
        }    
        
        while (location_of_prev_peak >= minimum_step)
        {
            location_of_prev_peak = previous_peak_location[location_of_prev_peak - minimum_step];
            if (0 != location_of_prev_peak) {
                no_of_flags ++;
            }    
        }
        
        no_of_flags = std::min(no_of_flags, flags_taken);
        max_flags = std::max(max_flags, no_of_flags);
        flags_taken --;
    }
        
    return max_flags;
}
