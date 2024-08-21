class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        // do a sanity check, what should we return 
        const auto m = board.size();
        if (m < 3) {
            return 0;
        }
        const auto n = board.front().size();
        if (n < 3) {
            return 0;
        }

        auto sortedNums = vector<pair<int, pair<int, int>>>{};
        sortedNums.reserve(m*n);
        for (auto i = 0; i < m; i++) {
            for (auto j=0; j <n; j++) {
                sortedNums.push_back({board[i][j], {i, j}});
            }
        }

        sort(sortedNums.begin(), sortedNums.end(), greater<pair<int, pair<int, int>>>());

        auto res = numeric_limits<long long int>::min();

        for (int a = 0; a < (m*n - 2); a++) {
            const auto aVal = sortedNums[a].first;
            const auto aX = sortedNums[a].second.first;
            const auto aY = sortedNums[a].second.second;
            if (3*((long long int)(aVal)) <= res) {
                break;
            }
            for (int b = a+1; b < (m*n -1); b++) {
                const auto bVal = sortedNums[b].first;
                const auto bX = sortedNums[b].second.first;
                const auto bY = sortedNums[b].second.second;

                if ((aVal + 2*((long long int) bVal)) <= res) {
                    break;
                }

                if (aX == bX || aY == bY) {
                    continue;
                }

                for (int c = b+1; c < (m*n); c++) {
                    const auto cVal = sortedNums[c].first;
                    const auto cX = sortedNums[c].second.first;
                    const auto cY = sortedNums[c].second.second;

                    if ((aVal + bVal + (long long int) (cVal)) <= res) {
                        break;
                    }

                    if (aX == cX || bX == cX || aY == cY || bY == cY) {
                        continue;
                    }

                    res = aVal +(long long int)(bVal) +(long long int) (cVal);
                    break;
                }
            }
        }

        return res;
    }
};