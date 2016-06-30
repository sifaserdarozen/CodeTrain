// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
#include <stack>

/** @brief struct holding value, index pair
 */
struct NumIndex
{
    int m_num;
    unsigned int m_index;
    NumIndex(int num, unsigned int index): m_num(num), m_index(index) {}
    NumIndex(): m_num(0), m_index(0) {}
};

/** @brief function returns index of a dominator
 * 
 *  Function aims to return any index of a dominator (leader) of vector A
 *  having elements [−2147483648 ... 2147483647] with size N 
 *  being in the range [1 .. 100000].
 *  A leader is defined to be number occuring more than half of the 
 *  members in this special cae
 *
 *  @param A input vector of numbers
 *  @retun number of possible index of leader
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of vector
    unsigned int N = A.size();
   
    // do a sanity check. if N < 2, return 0
    if (0 == N)
        return -1;
    
    // use stack to find more than half occuring number
    std::stack<NumIndex> max_num;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        if (0 == max_num.size())
        {
            max_num.push(NumIndex(A[index], index));
            continue;
        }
    
        if (max_num.top().m_num == A[index])
            max_num.push(NumIndex(A[index], index));
        else
            max_num.pop();
    }
    
    if (0 == max_num.size())    // check if there is a dominant number or not
        return -1;
        
    // check if it is a real dominator
    int counter = 0;
    int dominator_candidate = max_num.top().m_num;
    for (unsigned int index = 0; index < N; ++index)
        if (A[index] == dominator_candidate)
            counter++;
    if (2*counter <= N)
        return -1;
          
    return max_num.top().m_index;
}
