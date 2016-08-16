#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int n;    //!< number of elements in vectors
    std::cin >> n;
    
    std::vector<int> x(n);
    // read vector x
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> x[i];
    
    std::sort(x.begin(), x.end());
    
    std::vector<int> y(n);
    // read vector y
    for (unsigned int i = 0; i < n; ++i)
        std::cin >> y[i];
    
    std::sort(y.begin(), y.end());
    
    long long int steps = 0;
    long long int cummulative = 0;
    
    // prepare a difference matrix

    for (unsigned int i = 0; i < n; ++i)
    {
        int diff = y[i] - x[i];
        
        cummulative += diff;
        //if (cummulative > 0)
        //{
        //    std::cout << -1 << std::endl;
        //    return 0;
        //}
        
        if(diff < 0)
            steps += diff;
    }
    
    if (0 == cummulative)
        std::cout << -steps << std::endl;
    else
        std::cout << -1 << std::endl;
    
    
    
    
    return 0;
}

