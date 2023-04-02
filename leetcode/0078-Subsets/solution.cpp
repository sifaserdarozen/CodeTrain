class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        powerSet.push_back({});

        for (const auto& v: nums) {
            auto lenSet = size(powerSet);
            for (auto i = 0; i < lenSet; i++) {
                powerSet.push_back(powerSet[i]);
                powerSet.back().push_back(v);
            }
        }

        return powerSet;
    }
};