// Compute Complexity O(N)
// Space Complexity O(N)

func minimumLength(s string) int {
    // Calculate the occurances
    hist :=  make([]int, 26)
    for _, ch := range(s) {
        hist[ch - 'a']++
    }

    // if there is odd number, we can eliminate up to lst item
    // if there is an even number, we can eliminate up to last two
    remLength := 0
    for _, v := range hist {
        if 0 == v {
            continue
        } else if 1 == v % 2 {
            remLength += 1
        } else {
            remLength += 2
        }
    }

    return remLength
}