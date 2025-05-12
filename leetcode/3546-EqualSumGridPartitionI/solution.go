// Compute Complexity O(N*N)
// Space Complexity O(N)

func canBeDivided(vec []int, target int) bool {
    sum := 0
    for _, v := range vec {
        sum += v
        if sum == target {
            return true
        }
    }

    return false
}

func canPartitionGrid(grid [][]int) bool {
    // get row and column numbers, do sanity check
    m := len(grid)
    if m < 1 {
        return false
    }

    n := len(grid[0])
    if n < 1 {
        return false
    }

    // form sum of rows
    rowSums := make([]int, m)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            rowSums[i] += grid[i][j]
        }
    }

    // form sum of columns
    colSums := make([]int, n)
    for j := 0; j < n; j++ {
        for i := 0; i < m; i++ {
            colSums[j] += grid[i][j]
        }
    }

    //calcuate total
    sum := 0
    for _, v := range rowSums {
        sum += v
    }

    if sum % 2 != 0 {
        return false
    }

    target := sum / 2

    return canBeDivided(rowSums, target) || canBeDivided(colSums, target)
}