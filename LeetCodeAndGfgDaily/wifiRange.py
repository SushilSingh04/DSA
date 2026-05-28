class Solution:
    def wifiRange(self, s, x):
        # code here
        n = len(s)
        covered_till = -1

        for i in range(n):
            if s[i] == '1':
                left = max(0, i - x)
                right = min(n - 1, i + x)
    
                # gap found
                if left > covered_till + 1:
                    return False
    
                covered_till = max(covered_till, right)
    
        return covered_till == n - 1
            