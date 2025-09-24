// Use an hashmap to keep numbers and indexes
// Search the difference from target in each iteration

// Compute complexity O(N)
// Space complexity O(N)

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut numsMap = HashMap::new();
        for (idx, n) in nums.iter().enumerate() {
            let idx: i32 = idx as i32;
            let need = target - n;
            let v = numsMap.get(&need);
            if (!v.is_none()) {
                return vec![*v.unwrap(), idx];
            }
            numsMap.insert(n, idx);
        }
        return Vec::new();
    }
}
