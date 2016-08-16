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

using namespace std;

bool IsPolygon(std::vector<float> & a)
{
    // calculate sum up to n
    float sum = 0;
    for (unsigned int i = 0; i < (a.size() - 1); ++i)
        sum += a[i];
    
    if (sum > a.back())
        return true;
    else
        return false;
}

int main(){
    int n;
    cin >> n;
    
    vector<float> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    // do a sanity check
    if (1 == n)
    {
        std::cout << 2 << std::endl;
        return 0;
    }
    
    std::sort(a.begin(), a.end());
    int number_of_cuts = 0;
    while (!IsPolygon(a))
    {
        number_of_cuts ++;
        //split last element into two
        float last_elem = a.back();
        a.back() = last_elem / 2;
        a.push_back(last_elem - a.back());
        std::sort(a.begin(), a.end());
    }
    
    std::cout << number_of_cuts << std::endl;
    
    return 0;
}

