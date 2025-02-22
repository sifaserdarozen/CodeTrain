class Solution {
    private:
        bool isOk(int val, int h, vector<int>& piles) {
            auto sum = 0;
            for (const auto& p : piles) {
                sum += p/val + (p % val > 0 ? 1: 0); 
                if (sum > h) {
                    return false;
                }
            }
            return (sum <= h);
        }
        int calculateMinSpeed(int start, int end, int h, vector<int>& piles) {
            if (start >= end) {
                return end;
            }
            const auto mid = (start + end)/2;
    
            if (isOk(mid, h, piles)) {
                return calculateMinSpeed(start, mid, h, piles);
            } else {
                return calculateMinSpeed(mid+1, end, h, piles);
            }
        }    
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            const auto maxPile = *max_element(piles.begin(), piles.end());
            return calculateMinSpeed(1, maxPile, h, piles);
            
        }
    };
    