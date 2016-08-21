#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;    //!< number of elements in first list
    std::cin >> n;
    std::map<int, int> first_list;
    
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        
        std::map<int, int>::iterator it = first_list.find(value);
        if (it != first_list.end())
            it->second ++;
        else
            first_list[value] = 1;
    }
    
    int m;    //!< number of elements in second list
    std::cin >> m;
    std::map<int, int> second_list;
    
    for (int i = 0; i < m; ++i)
    {
        int value;
        std::cin >> value;
        
        std::map<int, int>::iterator it = second_list.find(value);
        if (it != second_list.end())
            it->second ++;
        else
            second_list[value] = 1;
    }
    
    std::map<int, int>::iterator it_fl = first_list.begin();
    std::map<int, int>::iterator it_sl = second_list.begin();
    
    while (true)
    {
        if (it_fl == first_list.end() && (it_sl == second_list.end()))
             break;
        else if (it_fl == first_list.end())
        {
            std::cout << it_sl -> first << " ";
            it_sl ++;
        }
        else if (it_sl == second_list.end())
        {
            std::cout << it_fl -> first << " ";
            it_fl ++;
        }
        else if ((it_fl -> first == it_sl -> first) && (it_fl ->second != it_sl -> second))
        {
            std::cout << it_sl -> first << " ";
            it_fl ++;
            it_sl ++;
        }
        else if (it_fl -> first > it_sl -> first)
        {
            std::cout << it_sl -> first << " ";
            it_sl ++;
        }
        else
        {
            it_fl ++;
            it_sl ++;           
        }
    }
    
    std::cout << std::endl;

    return 0;
}

