from queue import Queue
from collections import defaultdict
class Solution:
    def rightSideView(self, root):
        if not root:
            return []
        q = Queue()
        mp = defaultdict(lambda: None)
        q.put((0,root))

        while not q.empty():
            row, node = q.get()
            if row not in mp:
                mp[row] = node
            if node.right:
                q.put((row+1, node.right))
            if node.left:
                q.put((row+1, node.left))

        ans = []
        for row in sorted(mp.keys()):
            ans.append(mp[row].val)
        return ans