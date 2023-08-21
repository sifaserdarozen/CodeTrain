# Compute Complexity = O(S+T)
# Space Complexity = O(1) alphabet size

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        histogramS = {}
        for ch in s:
            histogramS[ch] = histogramS.get(ch, 0) + 1
        histogramT = {}
        for ch in t:
            histogramT[ch] = histogramT.get(ch, 0) + 1
        return histogramS == histogramT
