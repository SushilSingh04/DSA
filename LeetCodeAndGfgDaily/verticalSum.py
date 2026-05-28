from collections import deque
class Solution:
    def verticalSum(self, root):
        # code here
        q = deque([(root, 0)])
        
        mp = {}
        
        while q:
            node, dist = q.popleft()
            mp[dist] = mp.get(dist, 0) + node.data
            
            if node.left:
                q.append((node.left, dist - 1))
            if node.right:
                q.append((node.right, dist + 1))
        
        mp = dict(sorted(mp.items()))
        res = []
        
        for s in mp.values():
            res.append(s)
            
        return res