#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int q;    //!< numbe of queies
    std::cin >> q;
    
    for (unsigned int i = 0; i < q; ++i)
    {
        int n;   //!< indicates n of 2n x 2n matrix;
        std::cin >> n;
        
        std::vector<std::vector<int>> data(2*n, std::vector<int>(2*n));
        
        // read matrix values
        for (unsigned int a = 0; a < (2*n); ++a)
            for (unsigned int b = 0; b < (2*n); ++b)
                std::cin >> data[a][b];
        
        // calclate the possible sum;
        unsigned long int possible_sum = 0;
        for (unsigned int a = 0; a < n; ++a)
            for (unsigned int b = 0; b < n; ++b)
            {
            /*
                std::cout << "a:b " << a << "," << b << " -> " << a << "," << b << "=" << data[a][b] << " "
                                                               << a << "," << b << "=" << data[a][b] << " "
                                                               << a << "," << b << "=" << data[a][b] << " "
                                                               << a << "," << b << "=" << data[a][b] << " ";
                                                               */
                possible_sum += std::max(std::max(data[a][b], data[a][2*n - b - 1]), std::max(data[2*n - a - 1][b], data[2*n - a - 1][2*n - b - 1]));
            }
        // display the possible maximum
        std::cout << possible_sum << std::endl;     
    }
    
    return 0;
}

