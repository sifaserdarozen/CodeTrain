#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

unsigned int Compute(int power, long long int t)
{
    if (0 == t)
        return 1;
    
    int half = Compute(power, t/2);
    if (0 == (t % 2))
        return ((long long int)half * (long long int) half) % 1000000007;
    else
        return ((((long long int)half * (long long int)half) % 1000000007) * power) % 1000000007;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b;
    long long int t;
    std::cin >> a >> b >> t;
    
    int number_of_cells = 0;
    
    int factor = 0.5 * (a+b);
    
    number_of_cells = Compute(factor, t) % 1000000007;
    
    std::cout << number_of_cells << std::endl;
    
    return 0;
}

