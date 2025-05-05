// Space Complexity O(N)
// Compute Complexity O(logN)

class Solution {
    private:
        void calculateGrid(vector<vector<int>> & res, int i, int j, int size, int offset) {
            if (size == 1) {
                res[i][j] = offset;
                return;
            }
            
            const auto subSize = size / 2;
            calculateGrid(res, i, j + subSize, subSize, offset);
            calculateGrid(res, i + subSize, j + subSize, subSize, offset + subSize * subSize);
            calculateGrid(res, i + subSize, j, subSize, offset + 2 * subSize * subSize);
            calculateGrid(res, i, j, subSize, offset + 3 * subSize * subSize);
        }
        
    public:
        vector<vector<int>> specialGrid(int N) {
            const auto size = pow(2, N);
            vector<vector<int>> res(size, vector<int>(size));
            calculateGrid(res, 0, 0, size, 0);
    
            return res;
        }
    };