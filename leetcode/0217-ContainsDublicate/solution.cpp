// Compute complexity = O(N)
// Space complexity = O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> occurances;
        for (const auto& n : nums) {
            if (occurances.end() != occurances.find(n)) {
                return true;
            }
            occurances.insert(n);
        }
        return false;
    }
};

