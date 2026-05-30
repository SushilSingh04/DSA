from sortedcontainers import SortedSet, SortedDict
from typing import List
class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        q1 = SortedSet([0, 10_000_000])

        # size -> set of starting indices
        tm = SortedDict()
        tm[10_000_000] = SortedSet([0])

        res = []

        for q in queries:

            if q[0] == 1:
                # Insert point q[1]

                pos = q[1]

                idx = q1.bisect_right(pos)
                lower_bound = q1[idx - 1]
                upper_bound = q1[idx]

                cur_diff = upper_bound - lower_bound

                ts = tm[cur_diff]
                ts.remove(lower_bound)

                if not ts:
                    del tm[cur_diff]

                # Left interval
                l_diff = pos - lower_bound
                if l_diff not in tm:
                    tm[l_diff] = SortedSet()
                tm[l_diff].add(lower_bound)

                # Right interval
                u_diff = upper_bound - pos
                if u_diff not in tm:
                    tm[u_diff] = SortedSet()
                tm[u_diff].add(pos)

                q1.add(pos)

            else:
                # Query type 2
                x = q[1]
                length = q[2]

                idx = tm.bisect_left(length)

                query_result = False

                while idx < len(tm):
                    seg_len = tm.keys()[idx]
                    ts = tm[seg_len]

                    if ts[0] + length <= x:
                        query_result = True
                        break

                    idx += 1

                res.append(query_result)

        return res