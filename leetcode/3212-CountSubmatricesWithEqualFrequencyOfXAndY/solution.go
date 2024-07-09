// Compute complexity = O(N*M)
// Space complexity = O(N*M)

type Pair struct {
    First int
    Second int
}

func (self *Pair) Update(ch byte) {
    if ch == 'X' {
        self.First++
    } else if (ch == 'Y') {
        self.Second++
    }
}

func (self *Pair) Add(val *Pair) {
    self.First += val.First
    self.Second += val.Second
}

func numberOfSubmatrices(grid [][]byte) int {
    // get dimensions
    N := len(grid)
    if 0 == N {
        return 0
    }
    M := len(grid[0])
    if  0 == M {
        return 0
    }

    dic := make([][]Pair, N)
    for k, _ := range dic {
        dic[k] = make([]Pair, M)
    }

    // populate the first column of each row according to grid
    for i := 0; i < N; i++ {
        dic[i][0].Update(grid[i][0])
    }
    // then calculate the raw accumulation of occurances
    for i := 0; i < N; i++ {
        for j := 1; j < M; j++ {
            dic[i][j] = dic[i][j-1]
            dic[i][j].Update(grid[i][j])
        }
    }

    // then calculate the column accumulation of occurances
    for i := 1; i < N; i++ {
        for j := 0; j < M; j++ {
            dic[i][j].Add(&dic[i-1][j])
        }
    }

    // now iterate over the accumulation of X & Y values to calculate the
    // number of valid submatrices
    noOfSub := 0
    for _, raw := range dic {
        for _, v := range raw {
            if v.First == v.Second && v.First > 0 {
                noOfSub++
            }
        }
    }


    return noOfSub
}