// Compute Complexity O(S*N)
// Space complexity O(S)

class Solution {
public:
    std::vector<int> calculateHistogram(const std::string& str) {
        std::vector<int> hist('z' - 'a' + 1);
        for (const auto& c : str) {
            hist[c - 'a']++;
        }
        return hist;
    }

    struct vecHash {
        size_t operator()(std::vector<int>const& vec) const{
            size_t res = 0;
            for (const auto& i : vec) {
                res ^= std::hash<int>()(i);
            }
            return res;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::vector<int>, int, vecHash> dict;
        for (const auto& s : strs) {
            auto histogram = calculateHistogram(s);
            if (dict.end() != dict.find(histogram)) {
                res[dict[histogram]].push_back(s);
            } else {
                dict[histogram] = res.size();
                res.push_back({s});
            }
        }

        return res;
    }
};
