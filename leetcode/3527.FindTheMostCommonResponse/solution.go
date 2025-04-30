func findCommonResponse(responses [][]string) string {
	hist := make(map[string]int)
	for _, dayResponses := range responses {
		dayHist := make(map[string]struct{})
		for _, resp := range dayResponses {
			dayHist[resp] = struct{}{}
		}
		for resp, _ := range dayHist {
			hist[resp]++
		}
	}

	mostCommonResp := ""
	mostCommonCount := 0

	for resp, count := range hist {
		if count > mostCommonCount || (count == mostCommonCount && resp < mostCommonResp) {
			mostCommonResp = resp
			mostCommonCount = count
		}
	}
	return mostCommonResp
}
