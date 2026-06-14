from typing import List
class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        s = ''
        for word in words:
            weight = 0
            for ch in word:
                weight += weights[ord(ch) - 97]
            s += chr(96 + 26 - weight % 26)
        
        return s

