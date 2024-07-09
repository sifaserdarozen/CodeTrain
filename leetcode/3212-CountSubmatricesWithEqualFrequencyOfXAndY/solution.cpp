// Compute complexity = O(N*M)
// Space complexity = O(N*M)

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // get dimensions and do a asanity check
        const auto N = grid.size();
        if (0 == N) {
            return 0;
        }
        const auto M = grid.front().size();
        if (0 == M) {
            return 0;
        }

        // create a balance matrix that will contain pairs
        // where it will hold the cumulative 'X' and 'Y' occurances in the corresponding row
        // with adding the values with previous column
        vector<vector<pair<int, int>>> balance(N, vector<pair<int, int>>(M, {0, 0}));
        for (int i = 0; i < N; ++i){
            const auto ch = grid[i][0];
            balance[i][0].first =  (ch == 'X' ? 1 : 0);
            balance[i][0].second = (ch == 'Y' ? 1 : 0);    
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                const auto ch = grid[i][j];
                balance[i][j].first = balance[i][j-1].first + (ch == 'X' ? 1 : 0);
                balance[i][j].second = balance[i][j-1].second + (ch == 'Y' ? 1 : 0);
            }
        }

        // find overall cumulatives with adding the previous raw
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                balance[i][j].first += balance[i-1][j].first;
                balance[i][j].second += balance[i-1][j].second;
            }
        }

        // calculate number of solutions where finding the accumulated X & Ys of
        // previous columns. Check also occurance of X as well
        int noOfSol = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (balance[i][j].first == balance[i][j].second && balance[i][j].first > 0) {
                    noOfSol++;
                }
            }
        }

        return noOfSol;
    }
};