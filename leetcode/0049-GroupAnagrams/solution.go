// Compute Complexity O(SN)
// Space Complexity O(N)

type alph ['z'-'a'+1] int

func calculateHist(s string) *alph {
    res := alph{}
    for _, c := range(s) {
        res[c - 'a']++
    }
    return &res
}

func groupAnagrams(strs []string) [][]string {
    res := make([][]string, 0)
    dict := make(map[alph]int)

    for _, s := range(strs) {
        hist := calculateHist(s)
        if idx, ok := dict[*hist]; ok {
            res[idx] = append(res[idx], s);
        } else {
            dict[*hist] = len(res)
            res = append(res, []string{s})
        }
    } 

    return res;
}
