#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/** number of valleeys are counted by a valley start flag set during 
    transition from level 0 to downward, and a valley is consolidated
    when we have a valley started and transition from -1 to zero level
    Space complexity is O(1), Time complexity is O(n)
  */
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    
    std::string steps;
    std::cin >> steps;
    
    int number_of_valleys = 0;
    bool a_valley_started = false;
    int altitude = 0;
    for (unsigned int i = 0; i < steps.size(); ++i)
    {
        if ('U' == steps[i])
        {
            altitude ++;
            if ((0 == altitude) && (a_valley_started))
            {
                number_of_valleys ++;
                a_valley_started = false;
            }
        }
        else
        {
            if (0 == altitude)
                a_valley_started = true;
            altitude --;
        }
    }
    
    std::cout << number_of_valleys << std::endl;
    return 0;
}


