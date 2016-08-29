#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;    //!< number of trips
    std::cin >> t;
    
    for (int i = 0; i < t; ++i)
    {
        unsigned long long int n;    //!< desired number of pieces
        unsigned long long int k;    //!< total boxes at the store
        unsigned long long int b;    //!< number of box
        
        std::cin >> n >> k >> b;
        
        // detemine maximum and minimum numbe ofpossible pieces for given number of boxes
        // to find it the desired number of pieces is possible
        unsigned long long int min_choice = (0 == (b % 2)) ? ((b / 2) * (b + 1)) :  (((b + 1) / 2 ) * b);
        //unsigned long long int max_choice = (0 == (b % 2)) ? ((b / 2) * (k - b + k + 1)) : (((k - b + k + 1) / 2) * b) ;
        
        if ((min_choice > n))
        {
            std::cout << -1 << std::endl;
            continue;
        }
        std::set<int> choosen;
        std::string output = "";
        
        // since now we are sure that we may generate one series, try to find it
        while (n)
        {
            if (1 == b)
            {
                if ((n <= k) && (choosen.end() == choosen.find(n)))
                {
                    output += std::to_string(n);
                    std::cout << output << std::endl;
                }
                else
                    std::cout << -1 << std::endl;
                break;
            }
            
            b--;            
            unsigned long long int min_choice = (0 == (b % 2)) ? ((b / 2) * (b + 1)) :  (((b + 1) / 2 ) * b);
            
            if (min_choice > (n - b))
            {
                std::cout << -1 << std::endl;
                break;
            }
            
            unsigned long long int a_num = std::min(k, n - min_choice);
            k--;
                        
            //std::cout << a_num;
            n -= a_num;
            choosen.insert(a_num);
            
            output += std::to_string(a_num);
            output += " ";
        }
        
        // since now we are sure that we may generate one series, try to find it
    
    }
    
    return 0;
}

