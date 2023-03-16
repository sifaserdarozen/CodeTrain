# Compute Complexity = O(N)
# Space Complexity = O(N)

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        xorHist = { 0: 1}
        sum = 0
        currXor = 0

        for n in nums:
            currXor ^= n
            if currXor in xorHist:
                sum += xorHist[currXor]
                xorHist[currXor] += 1
            else:
                xorHist[currXor] = 1

        return sum