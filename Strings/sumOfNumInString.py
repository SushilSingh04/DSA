def findSum(self, s):
        #code here
        num  = 0
        sum = 0
        for ch in s:
            if ord(ch)-ord('0') >=0 and ord(ch) - ord('0') <= 9:
                num = num*10 + int(ch)
            else:
                sum += num
                num = 0
        sum += num
        return sum