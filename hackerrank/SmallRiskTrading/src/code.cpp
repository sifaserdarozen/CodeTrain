#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int n;    //!< number of available trades
    unsigned int k;    //!< number of allowed trades
    std::cin >> n >> k;
    
    std::vector<float> probabilities(n);
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> probabilities[i];
    
    std::vector<float> potential_gains(n);
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> potential_gains[i];
    
    std::vector<float> potential_losses(n);
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> potential_losses[i];
    
    std::vector<float> expected_gains(n);
    for (unsigned int i = 0; i < n; ++i)
        expected_gains[i] = (probabilities[i] * potential_gains[i]) - ((1.0 - probabilities[i]) * potential_losses[i]);
        
    std::sort(expected_gains.begin(), expected_gains.end());
    
    // calculate maximum of k
    double potential_gain = 0;
    for (unsigned int i = n - k; i < n; ++i)
        if (expected_gains[i] > 0)
            potential_gain += expected_gains[i];
    
    std::cout << std::fixed << std::setprecision(2) << potential_gain << std::endl;
    
    return 0;
}

