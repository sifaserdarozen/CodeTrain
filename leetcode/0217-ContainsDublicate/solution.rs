// Use hashmap to keep track of numbers
// Compute complexity O(N)
// Space complexity O(N)

// If we are restricted in memory
// we can sort the nums and iterate on the sorted vector
// compute complexity O(NlogN)
// space complexity O(1)

// Possible test cases
// Provide an empty vector {}
// Provide a single element vector {1}
// Provide a two element vector with same number {1, 1}
// Provide a three elemet vectors {0, 1, 2}, {1, 0, 1}, {0, 1, 1}, {1, 1, 0}, {1, 1, 1}
// Provide a large vector {0, 1, 2, 3, 4, ...}
// Provide a large vector {0, 1, 2, ..., 0}

use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut occurances = HashSet::new();
        for n in nums.iter() {
            if (occurances.contains(n)) {
                return true;
            }
            occurances.insert(n);
        }

        return false;
    }
}
