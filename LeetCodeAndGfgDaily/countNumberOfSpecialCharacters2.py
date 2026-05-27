class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        mp = {}
        for i in range(len(word)):
            ch = word[i]
            if ch == ch.upper() and ch not in mp:
                mp[ch] = i
            elif ch == ch.lower():
                mp[ch] = i
        # print(mp)
        
        cnt = 0
        for ch, index in mp.items():
            if ch == ch.lower() and ch.upper() in mp:
                upperIndex = mp[ch.upper()]
                lowerIndex = index
                if upperIndex > lowerIndex:
                    cnt += 1
        return cnt


