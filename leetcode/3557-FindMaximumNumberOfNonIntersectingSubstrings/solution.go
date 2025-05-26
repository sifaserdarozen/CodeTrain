// Compute Complexity O(N)
// Space Complexity O(N)

func maxSubstrings(word string) int {
    // form the histogram of chars
   var  hist [26]([]int)
    for k, _ := range hist {
        hist[k] = make([]int, 0)
    }

    for i := 0; i < len(word); i++ {
        hist[word[i] - 'a'] = append(hist[word[i]-'a'], i)
    }

    num := 0
    leastIdx := len(word)

    for i := 0; i < len(word); i++ {
        if (leastIdx == i) {
            num++
            leastIdx = len(word)
            continue
        }
        idx := word[i] - 'a'
        for (len(hist[idx]) > 0) && (hist[idx][0] <= i) {
            hist[idx] = hist[idx][1:len(hist[idx])]
        }
        for j := 0; j < len(hist[idx]); j++ {
            if (hist[idx][j] - i) < 3 {
                continue
            }
            if hist[idx][j] < leastIdx {
                leastIdx = hist[idx][j]
            }
            break
        }
    }

    return num 
}