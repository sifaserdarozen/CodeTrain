// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/** @brief function returning number of steps a frog needs to cross pool
 * 
 *  Function that return the the number of steps that a frog should 
 *  take in order to cross a pool starting from X, to Y in D intervals
 *  Assume that X <= Y, and X, Y, D is in the range [1 .. 1000000000]
 *  
 *  @param X start location
 *  @param Y target location
 *  @param D step size
 *  @retun required number of steps
 */
int solution(int X, int Y, int D) {
    // write your code in C++11 (g++ 4.8.2)
    
    // get the distance between start and target point
    int distance = Y - X;
    
    // find number of steps
    int step = (distance / D);
    
    // increment if there is a remainder from division
    if (0 != (distance % D))
        step++;
        
    return step;
}