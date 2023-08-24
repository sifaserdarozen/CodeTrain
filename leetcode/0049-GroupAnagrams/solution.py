# Compute Complexity O(SN)
# Space Complexity O(N)

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)

        size = ord('z') - ord('a') + 1
        for s in strs:
            hist = [0] * size
            for ch in s:
                hist[ord(ch) - ord('a')] += 1
            res[tuple(hist)].append(s)
        return res.values()
