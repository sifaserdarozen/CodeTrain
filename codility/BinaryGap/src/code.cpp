// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>    // for std::max()

/** @brief Function that calculates binary gap
 *  
 *  Binary gap may be stated as sequence of 0's that is surrounded by 1 at both end
 *  This function finds the maximal sequence of zeros that is in binary gap
 *  Assume that N is an integer in the range [1..2,147,483,647]
 * 
 *  @param N the number to check binary gap
 *  @return maximum value of binary gap
 */
int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
    
    // initialize maximum gap to zero
    int maximum_gap = 0;
    
    // do sanity check, if N < 3, there wont be any gapat all
    if (N < 3)
        return 0;
    
    // variables that will hold local gap and it's start
    int local_gap = 0;
    bool is_local_gap_started = false;
    
    // loop through N to check binary gaps
    while (N > 0)
    {
        // find if least significant bit is 1
        bool is_lsb_one = (N & 0x1);
        
        if (true == is_lsb_one)
        {
            is_local_gap_started = true;
            maximum_gap = std::max(maximum_gap, local_gap);
            local_gap = 0;
        }
        else if (true == is_local_gap_started)
            local_gap ++;
        
        // divide by 2 to get the next bit 
        N = N >> 1;
    }
        
    return maximum_gap;
}
