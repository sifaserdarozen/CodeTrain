// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <iostream>
#include <vector>

/** @brief function returns the maximum number of possible slices
 * 
 *  Function returns number of maximum possible equal size slice 
 *  that each have a peakin it. A peak is an index that has 
 *  greater value from it's precessor and successor
 *  N may vary between [1 .. 100000] and each element in the range
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
    
    std::vector<int> peaks_prefix_sum(N);
    peaks_prefix_sum[0] = 0;
  
    for (unsigned int i = 1; i < (N-1); ++i)
    {
        if ((A[i-1] < A[i]) && (A[i] > A[i+1]))
            no_of_peaks ++;
        peaks_prefix_sum[i] = no_of_peaks;
    }
    peaks_prefix_sum[N-1] = no_of_peaks;
    
    // do a sanity check. if there are no peaks, then
    // there will be no slice at allocate
    if (0 == no_of_peaks)
        return 0;

    // so the maximum number of slices may be number_of_peaks
    for (unsigned int i = no_of_peaks; i > 0; --i)
    {
        // first check if i is a perfect divisor, if not conitnue
        if (0 != (N % i))
            continue;
        
        // now we are sure that i is a perfect divisor of N, 
        // let's check if we have a peak in each slices
        unsigned int slice_length = N/i;
        bool peak_in_every_slice = true;
        for (unsigned int j = 0; j < i; ++j)
        {
            unsigned int start_of_slice = j*slice_length;
            unsigned int end_of_slice = start_of_slice + slice_length - 1;
            if (0 != start_of_slice)
                start_of_slice--;
            // if there is no peek in segment continue;
            if (peaks_prefix_sum[end_of_slice] <= peaks_prefix_sum[start_of_slice])
            {
                peak_in_every_slice = false;
                break;
            }
        }
        
        if (true == peak_in_every_slice)
            return i;
    } 
    
    return 0;
}
