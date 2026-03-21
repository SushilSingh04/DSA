# The barrier concept
# elements to the right of the first 1 remain the same since they all were 0's 
# (gets flipped due to 1's complement and added)
# elements to the left of the first 1 gets flipped (the carry flow stops and so the same bit as the 1's complement)

def twosComplement(bi):
    # code here
    found1 = 0
    res = ""
    for i in range(len(bi)-1,-1,-1):
        if found1 == 1:
            res += '1' if bi[i] == '0' else '0'
        else:
            res += bi[i]
        if found1 == 0 and bi[i] == '1':
            found1 = 1
    return res[::-1]

# print(twosComplement('110001100000'))

# Another way to find two's complement
# Two's complement is the number required to add to num to make it equal to the next power of 2
def twosComplementNumeric(num):
    tmp = num
    cnt = 0
    s = ''
    while tmp > 0:
        tmp //= 2
        cnt += 1
    twosComplement = 2**cnt - num 
    while twosComplement > 0:
        if twosComplement%2 == 0:
            s += '0'
        else:
            s += '1'
        twosComplement //= 2
    return s[::-1]

print(twosComplementNumeric(17))