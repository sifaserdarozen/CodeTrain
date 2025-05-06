// Use KPM pattern search with sweeping lines
// Space Complexity O(NM)
// Compute Complexity O(NM)

// kpm of a pattern is 
func generateKpm(pattern string) []int {
    kpm := make([]int, len(pattern))
    maxLen := 0
    for i:=1; i < len(pattern); i++ {
        if pattern[i] == pattern[maxLen] {
            maxLen++
            kpm[i] = maxLen
        } else {
            if maxLen == 0 {
                kpm[i] = 0
            } else {
                maxLen--
                i--             
            }
        }
    }
    return kpm
}

func FindPattern(grid [][]byte, pattern string, kpm []int, convert1Dto2D func (m, n, idx int)(int, int)) [][]bool {
    m := len(grid)
    n := len(grid[0])

    patternLoc := make([][]bool, m)
    for k, _ := range patternLoc {
        patternLoc[k] = make([]bool, n)
    }

    maxLen := 0
    toWrite := 0
    for idx := 0; idx < (m*n ); {
        i, j := convert1Dto2D(m, n, idx)
        if grid[i][j] == pattern[maxLen] {
            maxLen++
            idx++
        } else {
            if maxLen == 0 {
                idx++
            } else {
                maxLen = kpm[maxLen - 1]
            }
        }

        // we have a pattern starting at idx - len(pattern)
        // mark the locations using sweeping lines
        if maxLen == len(pattern) {
            startIdx := idx - len(pattern)
            if toWrite > startIdx {
                startIdx = toWrite
            }
            maxLen = kpm[maxLen - 1]

            for li := startIdx; li < idx; li++ {
                        a, b := convert1Dto2D(m, n, li)
                        patternLoc[a][b] = true
            }
            toWrite = idx
        }
    }
    return patternLoc
}

// convert 1D idx to 2D (i, j)
func convert1Dto2DHorizontal(m, n, idx int) (int, int)  {
    row := idx / n
    col := idx - n * row
    return row, col
}

// convert 1D idx to 2D (i, j)
func convert1Dto2DVertical(m, n, idx int) (int, int)  {
    col := idx / m
    row := idx - m * col
    return row, col
}

func FindLocsInBothPatterns(patternLocVertical, patternLocHorizontal [][]bool) int {
    m := len(patternLocVertical)
    n := len(patternLocVertical[0])

    sum := 0
    for i:= 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if patternLocVertical[i][j] && patternLocHorizontal[i][j] {
                sum++
            }
        }
    }

    return sum
}

func countCells(grid [][]byte, pattern string) int {

    // find KPM 
    kpm := generateKpm(pattern)

    // search pattern verically
    patternLocVertical := FindPattern(grid, pattern, kpm, convert1Dto2DVertical)

    // search pattern horizontally
    patternLocHorizontal := FindPattern(grid, pattern, kpm, convert1Dto2DHorizontal)

    // find cells are both in vertical and horizontal
    sum := FindLocsInBothPatterns(patternLocVertical, patternLocHorizontal)

    return sum
}