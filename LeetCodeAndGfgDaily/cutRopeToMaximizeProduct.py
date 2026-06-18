class Solution:
    def maxProduct(self, n):
        # code here
        if n == 2:
            return 1
        elif n == 3:
            return 2
        
        # base of the power should be 3 for result to be maximum
        pow_of_3 = n//3
        rem = n % 3
        
        # combine 3 and 1 to make 2 2's bcoz 3*1 < 2*2
        if rem == 1:
            pow_of_3 -= 1
            pow_of_2 = 2
        # only 1 power of 2
        elif rem == 2:
            pow_of_2 = 1
        # No power of 2 all powers of 3
        else:
            pow_of_2 = 0
        
        return (3**pow_of_3)*(2**pow_of_2)