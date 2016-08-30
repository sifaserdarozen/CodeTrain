#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    const int n = 5;    //!< number of slots
    
    std::vector<int> slots(n);    //!< original settings in slot machine
    
    // read original settings
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> slots[i];
    
    std::vector<int> desired_slots(n);    //!< numbers that we wish to be
    
    // read the wish numbers
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> desired_slots[i];
    
    int number_of_steps = 0;    //!< numberof steps to make slots into wished one
    for(unsigned int i = 0; i < n; ++i)
        number_of_steps += std::min(std::abs(slots[i] - desired_slots[i]), (10 - (std::abs(slots[i] - desired_slots[i]))));
                                   
    std::cout << number_of_steps << std::endl;
    
    return 0;
}

