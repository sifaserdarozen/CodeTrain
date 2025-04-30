#define MOD 1000000007

class Solution {
private:
    int getMod(long long int a, long long int b) {
        auto res = (a % MOD) * (b % MOD);
        return int(res % MOD);
    }
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const auto size = conversions.size() + 1;
        vector<vector<pair<int, int>>> convMap(size);
        
        for (const auto& conv : conversions) {
            convMap[conv[0]].push_back({conv[1],conv[2]});
        }

        vector<int> result(size, 0);
        result[0] = 1;

        queue<int> toProcess;
        toProcess.push(0);

        while(!toProcess.empty()) {
            const auto item = toProcess.front();
            toProcess.pop();
            for (const auto& target : convMap[item]) {
                 result[target.first] = getMod(result[item], target.second);
                 toProcess.push(target.first);
            }
        }

        return result;
    }
};