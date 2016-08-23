#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main(){
    unsigned int N = 26;    //!< number of lowercase letters
    vector<int> heights(N);
    
    // read heights of letters
    for (unsigned int i = 0; i < N ; ++i)
       cin >> heights[i];
    
    // read word of concern
    string word;
    cin >> word;
    
    int max_height = 0;
    // find maximum height letter in the word
    for (unsigned int i = 0; i < word.size(); ++i)
       max_height = std::max(max_height, heights[((int) word[i]) - 97]);
    
    // display heighlighted area
    std::cout << max_height * word.size() << std::endl;
    
    return 0;
}
