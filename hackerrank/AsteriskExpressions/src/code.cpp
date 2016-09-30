#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

#define MOD_VAL 1000000007

long long int CalculatePower(long long int a, long long int b)
{
    if (0 == b)
        return 1;
    else if (1 == b)
        return a % MOD_VAL;
    else
    {
        long long int result = 1;
        if (1 == b%2)
            result = a;
        
        long long int new_a = (a * a) % MOD_VAL;
        long long int partial_power =  CalculatePower(new_a, b/2);
        
        result = result * partial_power;
        return result % MOD_VAL;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int t;    //!< number of expressions
    std::cin >> t;
    
    for (unsigned int i = 0; i < t; ++i)
    {
        std::string e;
        std::cin >> e;
        
        std::vector<std::string> expression;
        std::stack<int> expression_queue;
        
        // split input string wrt '*'
        size_t start_pos = 0;
        size_t pos = e.find('*', start_pos);
        
        while (std::string::npos != pos)
        {
            if (pos != start_pos)
            {
                std::string previous_string = e.substr(start_pos, pos - start_pos);
                expression.push_back(previous_string);
            }
            expression.push_back("*");
            start_pos = pos + 1;
            if (e.size() == start_pos)    
                break;
            pos = e.find('*', start_pos);
        }
        
        // add last word if present
        if (e.size() != start_pos)
        {
            std::string last_string = e.substr(start_pos, e.size() - start_pos);
            expression.push_back(last_string);
        }
        
        //std::cout << "------------------" << std::endl;
        //std::cout << "string: " << e << std::endl;
        //for (unsigned int i = 0; i < expression.size(); ++i)
        //    std::cout << "   " << expression[i] << std::endl;
        
        bool fail = false;
        
        for (unsigned int i = 0; i < expression.size(); ++i)
        {
            if ("*" == expression[i])
            {
                if ((0 == expression_queue.size()) || ((expression.size() -1)== i))
                {
                    fail = true;
                    break;
                }
                else if ("*" == expression[i+1])
                {
                    i++;
                    if ((0 == expression_queue.size()) || ((expression.size() -1)== i) || ("*" == expression[i+1]))
                    {
                        fail = true;
                        break;
                    }
                    else
                    {
                        long long int item = std::stol(expression[i + 1]);
                        // item = item % MOD_VAL;
                        int result = CalculatePower(expression_queue.top(), item);
                        result = result % MOD_VAL;
                        expression_queue.pop();
                        expression_queue.push(result);
                        i++;
                    }
                
                }     
            }
            else
            {
                long long int item = std::stol(expression[i]);
                int item_mod = item % MOD_VAL;
                expression_queue.push(item_mod);
            }              
        }

        if (fail == true)
            std::cout <<  "Syntax Error" << std::endl;
        else
        {
            long long int item = 1;
            while (expression_queue.size())
            {
                //std::cout << expression_queue.top() << std::endl;
                item = item * expression_queue.top();
                item = item % MOD_VAL;
                expression_queue.pop();
            }
            std::cout << item << std::endl;
        }
              
    }
    
    
    return 0;
}

