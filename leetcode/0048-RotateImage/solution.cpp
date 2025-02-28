// Compute Complexity O(N*N)
// space complexity O(1)

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            const auto n = matrix.size();
            for (int i = 0; i <= (n-1)/2; i++) {
                for (int j = i; j < (n - 1 - i); j++) {
                    std::cout << i << " " << std::endl;
                    auto tmp = matrix[i][j];
                    matrix[i][j] = matrix[n-j-1][i];
                    matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                    matrix[n-i-1][n-j-1] = matrix[j][n-1-i];
                    matrix[j][n-1-i] = tmp;
                }
            }
        }
    };
    