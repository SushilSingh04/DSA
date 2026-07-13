import math

class Solution:
    def minOperations(self, b):
        # code here
        M = 10**9 + 7
        n = len(b)
        visited = [False]*(n+1)
        # 1 -- 3                4
        #  \  /                 |
        #    2                  5
        #(cycle_length = 3)   (cycle_length = 2)
        lcm = 1
        for i in range(1, n+1):
            if not visited[i]:
                cur = i
                cycle_length = 0
                while not visited[cur]:
                    visited[cur] = True
                    cur = b[cur-1]
                    cycle_length += 1
                # Take lcm of subsequent cycle lengths and previous lcm
                # Each number in the cycle would round to itself after `cycle_length` edges
                lcm = lcm*cycle_length//math.gcd(lcm, cycle_length)
        return lcm