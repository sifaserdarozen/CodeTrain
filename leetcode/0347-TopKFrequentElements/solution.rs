// Use hashmap to count occurances
// then use bucket sort to get first k
// Compute complexity = O(N)
// Space complexity = O(N)

use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut occurances = HashMap::new();

        for n in nums.iter() {
            match occurances.get(&n) {
                None => {
                    occurances.insert(n, 1);
                }
                Some(occurance) => {
                    occurances.insert(n, occurance + 1);
                }
            }
        }

        let mut buckets = vec![Vec::new(); nums.len() + 1];
        for (num, occurance) in occurances.iter() {
            buckets[*occurance].push(num);
        }

        let mut firstK = Vec::new();
        let target = k as usize;

        for (idx, val) in buckets.iter().enumerate().rev() {
            if val.len() != 0 {
                for it in val {
                    firstK.push(***it);
                    if firstK.len() == target {
                        return firstK;
                    }
                }
            }
        }

        return firstK;
    }
}
