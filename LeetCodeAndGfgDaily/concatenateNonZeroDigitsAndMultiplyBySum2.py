from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)
        pow_10 = [1]*(n + 1)
        for i in range(n):
            pow_10[i + 1] = (pow_10[i] * 10) % MOD

        pref_val = [0]*(n + 1)
        pref_sum = [0]*(n + 1)
        pref_cnt = [0]*(n + 1)

        for i in range(n):
            val = int(s[i])
            pref_sum[i + 1] = (pref_sum[i] + val) % MOD
            if val != 0:
                pref_val[i + 1] = (pref_val[i] * 10 + val) % MOD
                pref_cnt[i + 1] = pref_cnt[i] + 1
            else:
                pref_val[i + 1] = pref_val[i]
                pref_cnt[i + 1] = pref_cnt[i]
        
        ret_arr = []
        for l, r in queries:
            diff_cnt = pref_cnt[r + 1] - pref_cnt[l]
            num = pref_val[r + 1] - (pref_val[l] * pow_10[diff_cnt]) % MOD

            range_sum = pref_sum[r + 1] - pref_sum[l]
            ret_arr.append((num * range_sum) % MOD)

        return ret_arr


