// Use hashmap to count occurances
// then use bucket sort to get first k
// Compute complexity = O(N)
// Space complexity = O(N)

func topKFrequent(nums []int, k int) []int {
    occurances := make(map[int]int)
    for _, n := range nums {
        occurances[n]++
    }

    // do a bucket sort, create buckets
    buckets := make([]([]int), len(nums) + 1)

    for k, v := range occurances {
        buckets[v] = append(buckets[v], k)
    }

    kFreq := make([]int, 0)

    for idx := len(nums); idx >= 0; idx-- {
        for _, v := range buckets[idx] {
            kFreq = append(kFreq, v)
            if len(kFreq) == k {
                return kFreq
            }
        }
    }

    return kFreq  
}