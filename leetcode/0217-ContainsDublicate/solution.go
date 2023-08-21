// Compute complexity = O(N)
// Space complexity = O(N)
func containsDuplicate(nums []int) bool {
    occurances := make(map[int]struct{})

    for _, n := range(nums) {
        if _, ok := occurances[n]; ok {
            return true
        }
        occurances[n] = struct{}{}
    }

    return false
}
