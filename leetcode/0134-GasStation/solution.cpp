// Compute Complexity O(N)
// Space Complexity O(N)

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
                   auto sumExtraGas = 0;
            int bestStart = 0;
    
            const auto size = gas.size();
            auto bestExtraGas = - 1;
    
            for (auto i = 0; i < size; i++) {
                const auto  currExtraGas = gas[i] - cost[i];
                sumExtraGas += currExtraGas;
    
                if (bestExtraGas < 0) {
                    bestStart = i;
                    bestExtraGas = currExtraGas;
                } else {
                    bestExtraGas += currExtraGas;
                }
            }
    
            if (sumExtraGas < 0) {
                return -1;
            }
    
            return bestStart;
        }
    };