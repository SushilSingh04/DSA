class Solution:
    def constructList(self, queries):
        # code here
        #  [0,6,3,2]
        #  [0,0,0,4,5]
        n = len(queries)
        res = [0]
        cur = 0
        
        for i in range(n):
            op, x = queries[i]
            if op == 0:
                res.append(x^cur)
            else:
                cur ^= x

        for i in range(len(res)):
            res[i] ^= cur
            
        return sorted(res)