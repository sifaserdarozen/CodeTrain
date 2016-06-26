// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#define MAX_CROSSING_CARS 1000000000

#include <vector>

/** @brief function that returns the number of passing cars
 * 
 *  Input vector A contains N binary numbers. 
 *  A[k] = 1 means k'th car is heading west and A[k] = 0 means k'th car is heading east
 *  When two cars crosses, A[i] heads east and A[j] heads west and j>i.
 *  Function returns the number of passing cars.
 *  N the size of input vector A is an integer in the range [1 .. 100000]
 *  
 *  @param A input vector of integers
 *  @retun the number of passing cars.
 */
int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get size of the vactor
    unsigned int N = A.size();
        
    int cars_heading_west = 0;
    long long int cars_crossed = 0;
    
    // iterate through vector to calculate cars that will cross eachouther
    for (unsigned int index = 0; index < N; ++index)
    {
        if (0 == A[index])    // increment number of cars heading east
            cars_heading_west++;
        else   // means that all cumulated cars heading west will cross this single car
            cars_crossed += cars_heading_west;
    }
    
    if (cars_crossed > MAX_CROSSING_CARS)
        return -1;
    else  
        return (int)cars_crossed;
}
