// Compute complexity = O(N)
// Space complexity = O(N)

func numberOfAlternatingGroups(colors []int) int {
    N := len(colors)
    
    res := 0
    for idx, curr := range colors {
        prev := colors[(idx-1 +N)%N]
        next := colors[(idx+1)%N]
        if prev == next && prev != curr {
            res++
        }
    }

    return res;
}