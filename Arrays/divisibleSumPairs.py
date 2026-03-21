def divisibleSumPairs(k, ar):
    # Write your code here
    cntPairs = 0
    d = {}
    #     5 3

    # 2 8 6 8 4
    for i in range(len(ar)):
        rem = ar[i]%k
        target = (k - rem)%k
        if target in d:
            cntPairs += d[target]        
        d[rem] = d.get(rem,0)+1
    return cntPairs

print(divisibleSumPairs(5, {1,2,3,4,5}))