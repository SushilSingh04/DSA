from typing import List

class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        cnt = 0
        for subStr in patterns:
            if subStr in word:
                cnt += 1
        
        return cnt