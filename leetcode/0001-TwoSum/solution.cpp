// Compute Complexity O(N)
// Space Complexity O(N)

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numbers;
        for (int idx = 0; idx < nums.size(); idx++) {
            auto remaining = target - nums[idx];
            if (numbers.end() != numbers.find(remaining)) {
                return {idx, numbers[remaining]};
            }
            numbers[nums[idx]] = idx;
        }
        return {};
    }
};
