// Compute Complexity O(N)
// Space Complexity O(N)

func CalculateCount(hist map[int]int, target int) int {
	if targetCnt, ok := hist[target]; ok {
		return targetCnt
	}
	return 0
}

func countKDifference(nums []int, k int) int {
hist := make(map[int]int, 0)
counts := 0
for _, val := range nums {
	// find numbers that x - val = target => x = target + val
	counts += CalculateCount(hist, k + val)
	// find numbers that -x + val = target => x = val - target
	counts += CalculateCount(hist, val - k)              
	hist[val]++
}

return counts;
}