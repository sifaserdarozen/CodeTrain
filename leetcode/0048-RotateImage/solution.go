// compute Complexity O(N*N)
// Space Complexity O(1)

// Test cases
// []
// [1]
// [a b, c d] i:{0} j:{0}
// [a b c, d e f, g h i]

func rotate(matrix [][]int)  {
    n := len(matrix)
    for i := 0; i < n / 2; i++  {
        for j := i; j < (n -1 -i); j++ {
            tmp := matrix[i][j]
            matrix[i][j] = matrix[n-1-j][i]
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
            matrix[j][n-1-i] = tmp;
        }
    }
}