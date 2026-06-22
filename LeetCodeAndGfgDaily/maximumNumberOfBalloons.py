class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        mp = {}
        for ch in text:
            mp[ch] = mp.get(ch, 0) + 1
        
        minCnt = float('inf')
        for ch in 'balon':
            if ch in mp:
                if ch == 'l':
                    minCnt = min(minCnt, mp[ch]//2)
                elif ch == 'o':
                    minCnt = min(minCnt, mp[ch]//2)
                else:
                    minCnt = min(minCnt, mp[ch])
            else:
                return 0
        
        return minCnt
    
