// Compute Complexity = O(N)
// Space Complexity = O(N)

class Solution {
private:
    int CalculateCount(const unordered_map<int, int>& hist, int target) {
        const auto it = hist.find(target);
        if (hist.end() != it) {
            return it->second;
        }
        return 0;
    }

public:
    int countKDifference(vector<int>& nums, int k) {
        auto count = 0;
        unordered_map<int, int> hist;

        for (const auto& val : nums) {
            // x - val = target => x = target + val
            count += CalculateCount(hist, k + val);

            // find total number of numbers val such that
            // -(x - val) = target => x = val - target
            count += CalculateCount(hist, val - k);

            hist[val]++;
        }
        return count;
    }
};