// Compute Complexity O(N)
// Space Complexity O(N)
func twoSum(nums []int, target int) []int {
    numbers := make(map[int]int)
    for idx, n := range(nums) {
        remaining := target - n
        if idx2, ok := numbers[remaining]; ok {
            return []int {idx2, idx}
        }
        numbers[n] = idx
    }
    return []int {}
}
