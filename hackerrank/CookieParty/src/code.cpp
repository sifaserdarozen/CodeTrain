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


int main(){
    int n;
    int m;
    cin >> n >> m;
    
    int cookies_needed = m % n;
    
    // if there are some remainders,find the missing ones
    if (0 != cookies_needed)
        cookies_needed = n - cookies_needed;
    
    std::cout << cookies_needed << std::endl;
    
    return 0;
}
