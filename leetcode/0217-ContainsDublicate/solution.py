# Compute complexity = O(N)
# Space complexity = O(N)
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        occurances = set()
        for n in nums:
            if n in occurances:
                return True
            occurances.add(n)
        return False
