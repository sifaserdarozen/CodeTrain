#include <iostream>
#include <vector>
#include <algorithm>    // for std::swap

int main(){
    unsigned int n;    //!< number of data
    std::cin >> n;    // read number of data
    std::vector<int> a(n);
    
    for(unsigned int i = 0; i < n; ++i)
    {
       std::cin >> a[i];
    }
    
    unsigned int total_number_of_swaps = 0;
    
    // perform bubble sort algorithm
    for (unsigned int i = 0; i < n; i++)
    {
        // Track number of elements swapped during a single array traversal
        unsigned int number_of_swaps = 0;
    
        for (unsigned int j = 0; j < n - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                number_of_swaps++;
            }
        }
    
        // If no elements were swapped during a traversal, array is sorted
        if (number_of_swaps == 0) 
            break;
    
        // update total number of swaps
        total_number_of_swaps += number_of_swaps;   
    }

    // display results
    std::cout << "Array is sorted in " << total_number_of_swaps << " swaps." << std::endl;
    std::cout << "First Element: " << a.front() << std::endl;
    std::cout << "Last Element: " << a.back() << std::endl;

    return 0;
}

