class Solution:
    def sumAndMultiply(self, n: int) -> int:
        res = 0
        sumNum = 0
        while n:
            if n % 10 != 0:
                res = res * 10 + n % 10
                sumNum += n % 10
            n //= 10
        
        rev_res = 0
        while res:
            rev_res = rev_res * 10 + res % 10
            res //= 10

        return int(rev_res) * sumNum