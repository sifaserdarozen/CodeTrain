// Use hashmap to count occurances
// then use bucket sort to get first k
// Compute complexity = O(N)
// Space complexity = O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurances;
        for (const auto& n : nums) {
            occurances[n]++;
        }

        // use bucket sort
        // create nums.size() buckets
        vector<vector<int>> buckets(nums.size()+1);

        for (const auto& it : occurances) {
            buckets[it.second].push_back(it.first);
        }

        // get the first k numbers
        vector<int> firstK;
        for (auto it = buckets.rbegin(); it != buckets.rend(); it++) {
           for (const auto& n : *it) {
              firstK.push_back(n);
              if (firstK.size() == k) {
                return firstK;
              } 
           }
        }
        return firstK;        
    }
};