// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <string>
#include <vector>

/** @brief function returns minimum nucleotite over a given range
 * 
 *  Let S contains nucteotite sequence of N characters consisting letters A, C, G, T
 *  P and Q are two integer arrays of length M. Aim is to find minimum nucleotite in the range
 *  P[k] to Q[k] and put result in k'th index of resulting vector.
 *  Nucleotites A, C, G and T are weighted 1, 2, 3 and 4 correspondingly.
 *  
 *  @param S input nucleotite character string
 *  @param P start index vector
 *  @param Q end index vector
 *  @retun resulting minimum nucteotite asked in region.
 */
std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of arrays
    unsigned int N = S.size();
    unsigned int M = P.size();
    
    // declera cummulative prefix sums of each nucleotite
    std::vector<int> cum_A(N);
    std::vector<int> cum_C(N);
    std::vector<int> cum_G(N);
    std::vector<int> cum_T(N);
    
    int sum_A = 0;
    int sum_C = 0;
    int sum_G = 0;
    int sum_T = 0;
    
    for (unsigned int index = 0; index < N; ++index)
    {
        char curr_char = S[index];
        
        if ('A' == curr_char)
            sum_A ++;
        else if ('C' == curr_char)
            sum_C ++;
        else if ('G' == curr_char)
            sum_G ++;
        else
            sum_T ++;
            
        cum_A[index] = sum_A;
        cum_C[index] = sum_C;   
        cum_G[index] = sum_G;
        cum_T[index] = sum_T;        
    }
    
    std::vector<int> result(M);
    
    // now iterate over P and Q to find minimums
    for (unsigned int index = 0; index < M; ++index)
    {
        unsigned int start = P[index];
        unsigned int end = Q[index];
        
        if ((cum_A[end] > cum_A[start])|| (start && (cum_A[end] > cum_A[start-1])) || ((0 == start) && (1 == cum_A[0])))
            result[index] = 1;
        else if ((cum_C[end] > cum_C[start]) || (start && (cum_C[end] > cum_C[start-1])) || ((0 == start) && (1 == cum_C[0])))
            result[index] = 2;
        else if ((cum_G[end] > cum_G[start]) || (start && (cum_G[end] > cum_G[start-1])) || ((0 == start) && (1 == cum_G[0])))
            result[index] = 3;
        else
            result[index] = 4;

    }
    
    return result;
}
