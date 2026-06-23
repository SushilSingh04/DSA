class Solution:
    def maxPeopleDefeated(self, p):
        # code here
        i = 1
        cntDefeated = 0
        
        while i * i <= p:
            cntDefeated += 1
            p -= i * i
            i += 1
        
        return cntDefeated
        