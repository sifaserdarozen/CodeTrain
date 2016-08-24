#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int n;    //!< number of buildings
    std::cin >> n;
    
    std::vector<int> heights(n + 1);
    // read heights of buildings;
    for (unsigned int i = 1; i <= n; ++i)
        std::cin >> heights[i];
    
    unsigned int m;    //!< number of lazers that will be fired
    std::cin >> m;
    
    std::vector<int> lazers(m);
    // read location of lazers
    for (unsigned int i = 0; i < m; ++i)
        std::cin >> lazers[i];
    
    // sort lazer loactions if not already done
    std::sort(lazers.begin(), lazers.end());
    
    std::vector<int>::iterator lazer_it = lazers.begin();
    
    unsigned long long int total_heights = 0;
    for (unsigned int i = 1; i <= n; ++i)
    {
        while ((lazers.end() != lazer_it) && (*lazer_it <= (int)i))
            lazer_it++;
        
        //std::cout << i << " " << heights[i] << " " << *lazer_it << std::endl;
        
        if ((lazers.end() != lazer_it) && (*lazer_it > (int)i))
            total_heights += std::min(heights[i], (*lazer_it - (int)i));
        else
            total_heights += heights[i];  
    }
    
    std::cout << total_heights << std::endl;
    
    return 0;
}

