#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    long long int t;
    std::cin >> t;
    
    long long int b_sum = 0;
    long long int sum = 0;
    long long int step = 0;
    int index = 0;
    
    while(sum < t)
    {
        step = 3*std::pow(2, index);
        index ++;
        b_sum = sum;
        sum += step;
    }
    
    std::cout << (step - (t - b_sum - 1)) << std::endl;
    
    return 0;
}

