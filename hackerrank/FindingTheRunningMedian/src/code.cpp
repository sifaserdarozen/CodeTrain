#include <set>
#include <iostream>
#include <iomanip>    // for std::setprecision

int main()
{
    int n;
    std::cin >> n;

    std::multiset<int> lower_half_set;
    std::multiset<int> higher_half_set;
    std::cout << std::setprecision(1) << std::fixed ;
    
    for (int a_i = 0;a_i < n;a_i++)
    {
        // insert read element to smallest multiset;
        int a;
        std::cin >> a;
        
        if (lower_half_set.size() >= higher_half_set.size())
            higher_half_set.insert(a);
        else
            lower_half_set.insert(a);
        
        // rebalance the multiset if biggest element in lower_half_set
        // is bigger than the smallest element of higher_half_set
        
        if (a_i != 0)
        {
            int low_val = *higher_half_set.begin();
            int high_val = *lower_half_set.rbegin();
        
            if (low_val < high_val)
            {
                higher_half_set.erase(higher_half_set.begin());
                lower_half_set.erase(lower_half_set.find(high_val));
                higher_half_set.insert(high_val);
                lower_half_set.insert(low_val);
            }
        }        
        
        if (lower_half_set.size() > higher_half_set.size())
            std::cout << double(*lower_half_set.rbegin()) << std::endl;
        else if (higher_half_set.size() > lower_half_set.size())
            std::cout << double(*higher_half_set.begin()) << std::endl;
        else
            std::cout << (*lower_half_set.rbegin() + *higher_half_set.begin()) / ((double)2.0) << std::endl;
        
    }
    
    return 0;
}

