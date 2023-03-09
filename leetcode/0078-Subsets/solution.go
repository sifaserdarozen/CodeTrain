// Compute Complexity O(N*2^N)
// Space Complexity O(N)

func subsets(nums []int) [][]int {
    if 0 == len(nums) {
        return [][]int {[]int{}}
    }
    last := nums[len(nums) - 1]
    sets := subsets(nums[0:len(nums)-1])
    setsSize := len(sets)
    for i := 0; i < setsSize; i++ {
        copyS := make([]int, len(sets[i]))
        copy(copyS, sets[i])
        copyS = append(copyS, last)
        sets = append(sets, copyS)
    }
    return sets
}