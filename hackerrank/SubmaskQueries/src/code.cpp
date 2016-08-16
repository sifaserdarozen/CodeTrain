#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int StringToNum(std::string& s)
{
    int num = 0;
    
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        num = num << 1;
        num += ('1' == s[i])? 1: 0;
    }

    return num;
}

void SetNum(std::string& s, std::vector<long long int>& numbers, long long int x)
{  
    //std::cout << s << " : " << std::endl;
    
    int ones_in_s = 0;
    for(unsigned int i = 0; i < s.size(); ++i)
        if ('1' == s[i])
            ones_in_s ++;
    
    for(unsigned int k = 0; k < std::pow(2, ones_in_s); ++k)
    {
        int num = 0;
        int tmp = k;
        for(unsigned int i = 0; i < s.size(); ++i)
        {
            num = num << 1;
            if ('1' == s[i])
            {
               num += tmp % 2;
               tmp = tmp >> 1;
            }
        }
        numbers[num] = x;
        
        //std::cout << k << " " << std::hex << num << std::dec << " " << x << std::endl;
    }
    
    //std::cout << std::endl;
}

void XorNum(std::string& s, std::vector<long long int>& numbers, long long int x)
{
    //std::cout << s << " : " << std::endl;
    
    int ones_in_s = 0;
    for(unsigned int i = 0; i < s.size(); ++i)
        if ('1' == s[i])
            ones_in_s ++;
    
    for(unsigned int k = 0; k < std::pow(2, ones_in_s); ++k)
    {
        int num = 0;
        int tmp = k;
        for(unsigned int i = 0; i < s.size(); ++i)
        {
            num = num << 1;
            if ('1' == s[i])
            {
               num += tmp % 2;
               tmp = tmp >> 1;
            }
        }
        numbers[num] ^= x;
        
        //std::cout << std::hex << num << std::dec << " ";
    }   
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    std::cin >> n;
    std::cin >> m;
    
    int subsets = std::pow (2, n);
    
    std::vector<long long int> numbers(subsets, 0);
    
    std::vector<int> op;
    std::vector<long long int> arg;
    std::vector<int> mask;
    
    for (unsigned int i = 0; i < (unsigned int)m; ++i)
    {
        int type;
        std::cin >> type;
        
        if (3 == type)
        {
            std::string s;
            std::cin >> s;            
            int target = StringToNum(s);
            long long int result = 0;
            
            for (int k = op.size() -1; k >= 0; --k)
            {
                if (target != (mask[k] & target))
                     continue;
                result ^= arg[k];
                if(1 == op[k])
                     break;             
            }
            
            std::cout << result << std::endl;
            
            continue;
        }
        
        long long int x = 0;
        std::cin >> x;
        
        std::string s;
        std::cin >> s;
        
        op.push_back(type);
        arg.push_back(x);
        mask.push_back(StringToNum(s));    
    }
    return 0;
}
