// Compute Complexity = O(S+T)
// Space Complexity = O(1) alphabet size
#include <iostream>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        const auto size = 'z' - 'a' + 1;
        std::vector<int> histogramS(size, 0);
        for (const auto& c : s) {
            histogramS[std::tolower(c) - 'a']++;
        }
        std::vector<int> histogramT(size, 0);
        for (const auto& c : t) {
            histogramT[std::tolower(c) - 'a']++;
        }
        return histogramS == histogramT;
    }
};
