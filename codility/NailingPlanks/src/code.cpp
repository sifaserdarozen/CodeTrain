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

struct Nail
{
    int m_pos;
    unsigned int m_idx;
    Nail(int pos = 0, unsigned int idx = 0): m_pos(pos), m_idx(idx) {}
    bool operator < (const Nail& rh) const {return (((m_pos < rh.m_pos)) ? true : false);}
};


/** @brief function returns the mininum number of nails to join flanks
 * 
 *  A and B are two vectors indicating start and end positions of flanks.
 *  A[i] is start and B[i] isend position of flank i. A & B length will be
 *  in range [1 .. 30000]. C is nail array that indicates postion of nails.
 *  size of C will be [1 .. 30000]. A flank i is said to be joined with nail
 *  j if A[i] <= C[j] <= B[i].
 *  Elements of A, B and C will be in range [1 .. 60000]
 *  
 *  @param A input vector indicating start of flanks
 *  @param B input vector indicating end of flanks
 *  @param C nail positions
 *  @retun minimum number of nails necessary to join flanks
 */
int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
{
    // get size of flanks
    unsigned int N = A.size();
    
    // get size of nails
    unsigned int M = C.size();
    std::vector<Nail> nails(M);
    for (unsigned int i = 0; i < M; ++i)
        nails[i] = Nail(C[i], i);
        
    std::sort(nails.begin(), nails.end());
    
    int result = -1;
    // loop through A nd B to detect the minimum possible nails to fix flanks
    for (unsigned int i = 0; i < N; ++i)
    {
        int start_of_flank = A[i];
        int end_of_flank = B[i];
        
        // do a binary search in Nails to find closest to xero index nail location satisfying
        // fix operation;
        
        int local_index = -1;
        int local_pos = 0;
        int start_pos = 0;
        int end_pos = M-1;
        int idx_pos = 0;
        while (start_pos <= end_pos)
        {
            idx_pos = (start_pos + end_pos) / 2;
            local_pos = nails[idx_pos].m_pos;
            
            if (local_pos >= start_of_flank)
            {
                local_index = idx_pos;
                end_pos = idx_pos - 1;
            }
            else
                start_pos = idx_pos + 1;
        }
        
        if (-1 == local_index)
            return -1;
        if (local_pos > end_of_flank)
            return -1;
        
        // search from local index to upper to find a better (closer to zero index)
        // satisfying coverage requirement

        unsigned int local_result = nails[local_index].m_idx;
        for(unsigned int j = local_index + 1; j < M; ++j)
        {
            if (nails[j].m_pos > end_of_flank)
                break;
            else
            {
                if (nails[j].m_idx < local_result)
                   local_result = nails[j].m_idx;
                if ((int)local_result < result)
                    break;
            }
        }

        if ((int)local_result > result)
            result = local_result;
        
    }
      
    return ((-1 == result)? result : (result + 1));

}