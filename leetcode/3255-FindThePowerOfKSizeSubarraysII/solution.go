// Compute Complexity O(N)
// space complexity O(1)

func resultsArray(nums []int, k int) []int {
    // do a sanity check
    size := len(nums)
    res := make([]int, 0)
    if size < k {
        return res
    }

    lastVal := nums[0]
    strike := 1

    for idx := 1; idx < k; idx++ {
        if nums[idx] == (lastVal + 1) {
            strike++
        } else {
            strike = 1
        }
        lastVal = nums[idx]
    }

    if strike >= k {
        res = append(res, lastVal)
    } else {
        res = append(res, -1)   
    }

    for idx := k; idx < len(nums); idx++ {
        if nums[idx] == (lastVal + 1) {
            strike++
        } else {
            strike = 1
        }
        lastVal = nums[idx]
        if strike >= k {
            res = append(res, lastVal)
        } else {
            res = append(res, -1)   
        }
    }
    
    return res
}