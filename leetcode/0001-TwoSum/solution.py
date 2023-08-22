# Compute Complexity O(N)
# Space Complexity O(N)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numbers = {}
        for idx, n in enumerate(nums):
            remaining = target - n
            if remaining in numbers:
                return [numbers[remaining], idx]
            numbers[n] = idx
        return []
