// Compute Complexity = O(N)
// Space Complexity = O(N)

func beautifulSubarrays(nums []int) int64 {
    xorHist := map[int]int64 {0: 1}
    sum := int64(0)
    currXor := 0

    for _, v := range(nums) {
        currXor ^= v
        sum += xorHist[currXor]
        xorHist[currXor]++
    }

    return sum
}