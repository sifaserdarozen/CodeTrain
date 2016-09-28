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

/** Function detecting word coverage
 *  
 *  Function detects if content of ransom vector may be obtained
 *  from elements ofmagazine vector.
 *
 *  Time complexity is O(n + m), where nand m are vector sizes
 *  Spacecomlexity is O(m), at worst case where m is pool size
 *
 *  Example: For magazine: "give me one grand today night"
 *               ransom:   "give one grand today"
 *               result:   "YES"
 *
 *  @param magazine word pool to chose from
 *  @param ransom target words to produce from magazine
 *  @return possibility of generating ransom from magazine
 */
bool ransom_note(vector<string> magazine, vector<string> ransom) {
    std::map<std::string, int> word_pool;

    for (unsigned int i = 0; i < magazine.size(); ++i)
        if (word_pool.end() == word_pool.find(magazine[i]))
            word_pool[magazine[i]] = 1;
        else
            word_pool[magazine[i]]++;
    
    for (unsigned int j = 0; j < ransom.size(); ++j)
        if (word_pool.end() == word_pool.find(ransom[j]))
            return false;
        else
            if (0 == word_pool[ransom[j]])
                  return false;
            else
                  word_pool[ransom[j]]--;
                  
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

