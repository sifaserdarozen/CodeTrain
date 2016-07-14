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


/** @brief function returns the mininum possible sum
 *  of subpatrition of an array that divided into K partitions
 * 
 *  Assume A is an array of size N where N is [1 .. 100000]. 
 *  It is required to subpartition this array into K possibly
 *  non same size subpartitions. Some partitions are allowed to be
 *  empty. K is in the range [1 .. 100000].
 *  M is said to be maximum possible value A[i]can be: A[i] <= M 
 *  M is in range [0 .. 10000]
 *  
 *  @param A input vector
 *  @param K number of partitions
 *  @param M maximum value of A[i]
 *  @retun minimum number of jumps to cross the river
 */
int solution(int K, int M, std::vector<int> &A)
{
    // get size of array A
    unsigned int N = A.size();
    
    // get sum of elements of array Assume
    int sum_of_A = 0;    // 100000 elements of each 10000 will fit in int
    int max_of_A = INT_MIN;    // set maximum of A to given upper limit M
    for (unsigned int i = 0; i < N; ++i)
    {
        sum_of_A += A[i];
        max_of_A = std::max(max_of_A, A[i]);
    }
    
    // maximum possible distance will be if there is only one partition
    int max_dist = sum_of_A;
    
    // if K is 1, the only possible solution is max_dist;
    if (1 == K)
        return max_dist;
        
    // minimum possible distance will be if there are many partitions 
    // which one of them will contain maximum element of the array
    int min_dist = max_of_A;
    
    // if K is greater than array length, the only feasable solution is min_dist
    if ((unsigned int)K >= N)
        return min_dist;

    // now start doing a binary search between possibility of index_dist
    // in K partitions using binary search in possbile space of [min_dist max_dist]
    
    int result_dist = max_dist;
    
    while (min_dist <= max_dist)
    {
        //let index_dist be mid of the range
        int index_dist = (max_dist + min_dist) / 2;
    
        // now do search if index_dist be achieved in how many segments
        int no_of_partitions = 1;
        int partition_size = 0;
        for (unsigned int i = 0; i < N; ++i)
        {
            if ((partition_size + A[i]) > index_dist)
            {
                partition_size = A[i];
                no_of_partitions ++;
            }
            else
                partition_size += A[i];
        }
        
        // now compare required partition with K and update search range accordingly;
        if (no_of_partitions > K)
        {
            // we should increase partition size to decrease number of partitions
            min_dist = index_dist + 1;
        }
        else
        {   // we may decrease partition size so that use more partitions
            max_dist = index_dist - 1;
            result_dist = index_dist;
        }
    }
   
    return result_dist;

}