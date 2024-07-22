// Compute Complexity O(N)
// Space Complexity O(1)

func doesAliceWin(s string) bool {
    // count the number of vowels
    noOfVowels := 0
    for _, ch := range s {
        if 'a' == ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch {
            noOfVowels++
        }
    }

    return 0 != noOfVowels
}