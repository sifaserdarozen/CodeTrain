// Compute Complexity O(N)
// Space Complexity O(1)

func maxOperations(s string) int {
    shouldAdd := false
    possibleOperations := 0
    noOf1s := 0

    // loop through to find possible number of operations
    for _, ch := range s {
        if '0' == ch {
            shouldAdd = true
        } else if '1' == ch {
            if shouldAdd {
                possibleOperations += noOf1s
                shouldAdd = false
            }
            noOf1s++
        } else {
            fmt.Println("This should not happen")
        }
    }

    // add the ones due to line ending
    if shouldAdd {
        possibleOperations += noOf1s
    }

    return possibleOperations
}