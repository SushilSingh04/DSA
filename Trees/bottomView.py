from queue import Queue
from collections import defaultdict

class Solution:
    def topView(self, root):
        # code here
        if not root:
            return []
        mp = defaultdict(lambda: None)
        q = Queue()
        q.put((0,root))
        
        while not q.empty():
            col, node = q.get()
            mp[col] = node
            if node.left:
                q.put((col-1, node.left))
            if node.right:
                q.put((col+1, node.right))
        ans = []
        for col in sorted(mp.keys()):
            ans.append(mp[col].data)
        return ans