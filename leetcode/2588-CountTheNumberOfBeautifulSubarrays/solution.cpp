// Compute Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        std::unordered_map<int, long long> xorHist;
        xorHist[0] = 1;

        long long sum = 0;
        int currXor = 0;

        for (const auto& n: nums) {
            currXor ^= n;
            sum += xorHist[currXor];
            xorHist[currXor]++;
        }

        return sum;
    }
};