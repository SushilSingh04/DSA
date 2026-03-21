from queue import Queue
from typing import List, Optional
from collections import defaultdict
class Solution:
    def verticalTraversal(self, root) -> List[List[int]]:
        q = Queue()
        mp = defaultdict(lambda: defaultdict(list))
        q.put((root,0,0))
        while not q.empty():
            node,col,row = q.get()
            mp[col][row].append(node.val)
            if node.left:
                q.put((node.left, col-1, row+1))
            if node.right:
                q.put((node.right, col+1, row+1))
        ans = []
        for col in sorted(mp.keys()):
            curr = []
            for row in sorted(mp[col].keys()):
                curr.extend(sorted(mp[col][row]))
            ans.append(curr) 
        return ans