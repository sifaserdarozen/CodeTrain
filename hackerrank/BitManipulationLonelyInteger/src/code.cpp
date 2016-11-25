#include <vector>
#include <iostream>

/** @fn LonelyInteger
 *  @brief Function finding lonley integer
 *
 *  Function finds the lonley integer in agroup of
 *  dublicate numbers.
 *
 *  @param a input vector of numbers
 *  @return the lonely number
 */
int LonelyInteger(const std::vector<int>& a)
{
    int tmp = a[0];
    
    for (unsigned int i = 1; i < a.size(); ++i)
        tmp ^= a[i];
    
    return tmp;
}

int main()
{
    unsigned int n;    //!< number of elements
    std::cin >> n;
    std::vector<int> numbers(n);
    
    // read numbers
    for (unsigned int i = 0; i < n; ++i)
       std::cin >> numbers[i];
    
    // calculate and display the lonely integer
    std::cout << LonelyInteger(numbers) << std::endl;
    
    return 0;
}

