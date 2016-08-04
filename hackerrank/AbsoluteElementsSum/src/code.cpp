#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;    //!< number of elements
    std::cin >> N;
    
    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i)
        std::cin >> numbers[i];
    
    int Q;    //!< number of queriess
    std::cin >> Q;
    
    std::vector<int> queries(Q);
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> queries[i];
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    int zero_index = -1;
    long long int negative_sum = 0;
    int negative_numbers = 0;
    long long int positive_sum = 0;
    int positive_numbers = 0;
    
    for (int i = 0; i < N; ++i)
    {
        if (numbers[i] < 0)
        {
            negative_sum += std::abs(numbers[i]);
            negative_numbers ++;
            zero_index = i;
        }
        else
        {
            positive_sum += numbers[i];
            positive_numbers ++;
        }
    }
   
    int accum = 0;
     
    for (int i = 0; i < Q; ++i)
    {    
        int query = queries[i];
        int part_i = zero_index;
        
        //std::cout << "query: " << query << " accum: " << accum << " zero index: " << zero_index << std::endl;
        //std::cout << "negative sum: " << negative_sum << " numbers: " << negative_numbers << std::endl;
        //std::cout << "positive sum: " << positive_sum << " numbers: " << positive_numbers << std::endl;
             
        if (query < 0)
        {
            long long int part_sum = 0;
            for(int ii = zero_index + 1; ((ii < N) && ((numbers[ii] + query + accum) < 0)); ++ii)
            {
                part_sum += std::abs(numbers[ii] + accum);
                part_i = ii;
            }
            
            //std::cout << "part_i: " << part_i << " part_sum: "  << part_sum << std::endl;
            
            negative_sum += negative_numbers*std::abs(query);
            negative_sum += ((part_i - zero_index)*std::abs(query) - part_sum);
            negative_numbers += (part_i - zero_index);
            positive_sum -= part_sum;
            positive_numbers -= (part_i - zero_index);
            positive_sum -= positive_numbers*std::abs(query);           
        }
        else
        {
            long long int part_sum = 0;
            for(int ii = zero_index; ((ii >= 0) && ((numbers[ii] + query + accum) >= 0)); --ii)
            {
                part_sum += std::abs(numbers[ii] + accum);
                part_i = ii - 1;
            }
            
            //std::cout << "part_i: " << part_i << " part_sum: "  << part_sum << std::endl;
            
            positive_sum += positive_numbers*std::abs(query);
            positive_sum += ((zero_index - part_i)*std::abs(query) - part_sum);
            positive_numbers += (zero_index - part_i);
            negative_sum -= part_sum;
            negative_numbers -= (zero_index - part_i);
            negative_sum -= negative_numbers*std::abs(query);                     
        }
        accum += query;
        zero_index = part_i;
        
        std::cout << (negative_sum + positive_sum) << std::endl;
    }
    
    return 0;
}

