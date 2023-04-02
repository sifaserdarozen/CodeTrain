func subsets(nums []int) [][]int {
    powerSet := make([][]int, 0)
    powerSet = append(powerSet, []int{})

    for _, v := range(nums) {
        lenSet := len(powerSet)
        for i := 0; i < lenSet; i++ {
            copySet := make([]int, len(powerSet[i]))
            copy(copySet, powerSet[i])
            copySet = append(copySet, v)
            powerSet = append(powerSet, copySet)
        }
    }

    return powerSet
}