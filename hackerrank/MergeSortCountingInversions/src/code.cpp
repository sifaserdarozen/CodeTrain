#include <vector>
#include <iostream>
#include <algorithm>

/** @fn Merge
 *
 *  Function that merges two sorted sub arrays of 
 *  a[start: r_start-1] and a[r_start:end] to form sorted a[start:end]
 *  As merge sort needs O(n) space complexity, we also have a
 *  temporary vectory tmp_a and used in substeps
 * 
 *  Example:
 *    input array [4 5 1 2 3] and start = 0, r_start = 2, end = 4 
 *    (subvectors of [4 5] and [1 2 3]) needs 6 inversions to be
 *    merged into [1 2 3 4 5]
 * 
 *  @param a input vector that will be sorted
 *  @param temp_a temporary vector that will be used in sorting
 *  @param start start of region, start index of first subvector
 *  @param r_start start index of second subvector
 *  @param end end of region, end of second subvector
 *  @return number of inversions to perform merge of vector [start:end]
 */
unsigned int Merge(std::vector<int>& a, std::vector<int>& temp_a, unsigned int start, unsigned int r_start, unsigned int end)
{
    unsigned int no_of_inversions = 0;
    
    unsigned int la_start = start;
    unsigned int ra_start = r_start;
    unsigned int da_start = start;
    
    for (unsigned int i = 0; (i < (end - start + 1)); ++i)
    {
        if (la_start == r_start)
        {
            temp_a[da_start] = a[ra_start];
            ra_start++;
        }
        else if (ra_start > end)
        {
            temp_a[da_start] = a[la_start];
            la_start++;
        }
        else if (a[la_start] <= a[ra_start])
        {
            temp_a[da_start] = a[la_start];
            la_start++;
        }
        else
        {
            temp_a[da_start] = a[ra_start];
            ra_start++;
            no_of_inversions += (r_start - la_start);
        }
        da_start++;
    }
    
    std::copy(temp_a.begin() + start, temp_a.begin() + end + 1, a.begin() + start);

    return no_of_inversions;  
}

/** @fn ModifiedMergeSort
 *
 *  Function that calculates number of inversions to sort
 *  input vector a from start to end index. For sorting merge sort will be used.
 *  As merge sort needs O(n) space complexity, we also have a
 *  temporary vectory tmp_a and used in substeps
 *
 *  Example:
 *    input array [5 4 3 2 1] needs 10 inversions to be
 *    sorted into [1 2 3 4 5]
 * 
 *  @param a input vector that will be sorted
 *  @param temp_a temporary vector that will be used in sorting
 *  @param start start index in vector a to begin operation
 *  @param end end index in vector a to end operation
 *  @return number of inversions to sort the vector a
 */
unsigned long long int ModifiedMergeSort(std::vector<int>& a, std::vector<int>& temp_a, unsigned int start, unsigned int end)
{
    unsigned long long int no_of_inversions = 0;
    
    if (start < end)
    {
        unsigned int mid = (start + end) / 2;
        no_of_inversions += ModifiedMergeSort(a, temp_a, start, mid);
        no_of_inversions += ModifiedMergeSort(a, temp_a, mid + 1, end);
        no_of_inversions += Merge(a, temp_a, start, mid + 1, end);
    }
    
    return no_of_inversions;
}

/** @fn CountInversions
 *
 *  Function that calculates number of inversions to sort
 *  input array a. For sorting merge sort will be used.
 *  As merge sort needs O(n) space complexity, we create a
 *  temporary array tmp_a and use it at substeps
 *
 *  Example:
 *    input array [5 4 3 2 1] needs 10 inversions to be
 *    sorted into [1 2 3 4 5]
 * 
 *  @param a input array that will be sorted
 *  @return number of inversions to sort the array
 */
unsigned long long int CountInversions(std::vector<int>& a)
{
    std::vector<int> temp_a(a.size(), 0);    //!< temporary array that will be used in mergesort
    return ModifiedMergeSort(a, temp_a, 0, a.size()-1);
}

int main()
{
    unsigned int nit;    //!< number of iterations
    std::cin >> nit;
    
    // repeat experiment nit times
    for(unsigned int i = 0; i < nit; ++i)
    {
        unsigned int n;    // number of elements
        std::cin >> n;
        
        std::vector<int> arr(n);    // element array
        for(unsigned int j = 0; j < n; ++j)
           std::cin >> arr[j];

        // display number of inversions in this iteration
        std::cout << CountInversions(arr) << std::endl;
    }
    
    return 0;
}

