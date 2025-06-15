// Use a prefix array to keep max and min numbers uf to that idx
// Then max multiplication can be calculated with num[idx] and prefix array[idx-m +1]

// Compute Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        if ((nums.size() < m) || m <= 0 ){
            return 0;
        }

        pair<int, int> backPair = {INT_MIN, INT_MAX};
        vector<pair<int, int>> prefix(nums.size());

        // calculate a prefix array that will keep maximum and minimum numbers up to that idx
        for (int idx = 0; idx < nums.size(); idx++) {
            backPair = {max(backPair.first, nums[idx]), min(backPair.second, nums[idx])};
            prefix[idx] = backPair;
        }

        long long int maxMul = numeric_limits<long long int>::min();
        
        for (int idx = m - 1; idx < nums.size(); idx++) {
            if (nums[idx] > 0) {
                maxMul = max(maxMul, (long long int)nums[idx] * prefix[idx - m + 1].first);
            } else {
                maxMul = max(maxMul, (long long int)nums[idx] * prefix[idx - m + 1].second);
            }
        }
        
        return maxMul;
    }
};