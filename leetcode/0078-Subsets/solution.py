class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        powerSet = []
        powerSet.append([])

        for v in nums:
            lenSet = len(powerSet)
            for i in range(lenSet):
                powerSet.append(powerSet[i].copy())
                powerSet[-1].append(v)

        return powerSet