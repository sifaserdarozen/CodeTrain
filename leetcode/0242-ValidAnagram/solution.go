// Compute Complexity O(N+M)
// Space Complexity = O(1) alphabet size

func isAnagram(s string, t string) bool {
    histogramS := make(map[rune]int)
    for _, r := range(s) {
        histogramS[unicode.ToLower(r)]++
    }
    histogramT := make(map[rune]int)
    for _, r := range(t) {
        histogramT[unicode.ToLower(r)]++
    }

    // check if lengths are equal first
    if len(histogramS) != len(histogramT) {
        return false
    }

    // then compare individual occurances
    for k, v := range(histogramS) {
        v2, ok := histogramT[k]
        if !ok || v != v2 {
            return false
        }
    }

    return true
}
