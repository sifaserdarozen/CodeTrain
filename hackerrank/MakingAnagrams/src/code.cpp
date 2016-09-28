#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define NO_OF_SYMBOLS ('z' - 'a' + 1)

using namespace std;

/** @brief function calculating histogram difference
 *
 *  Function calculates difference between two strings. Difference is
 *  measured in terms of necessery element deletions to make strings
 *  anagram of eachother.
 *
 *  Time compexity is O(size(a) + size(b) + 26) assuming 26 symbols
 *  Space compexity is O(26) assuming 26 symbols
 *
 *  Example: For inputs of "cde" and "abe", result is 4
 *
 *  @param a first input string
 *  @param b second input string
 *  @return number of diffrence between input strings
 */
int number_needed(string a, string b) {
    std::vector<int> histogram(NO_OF_SYMBOLS, 0);
    
    // process content of string a
    for (unsigned int i = 0; i < a.size(); ++i)
        histogram[a[i] - 'a']++;
    
    // process content of string b
    for (unsigned int i = 0; i < b.size(); ++i)
        histogram[b[i] - 'a']--;
    
    unsigned int deletion_count = 0;
    
    // count the difference
    for (unsigned int i = 0; i < NO_OF_SYMBOLS; ++i)
        deletion_count += std::abs(histogram[i]);
    
    return deletion_count;   
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

