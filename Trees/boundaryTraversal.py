class Solution:
    def isLeaf(self, root):
        if not root.left and not root.right:
            return True
        return False
       
    def leftBoundary(self, root, res):
        if not root:
            return
        if not self.isLeaf(root):
            res.append(root.data)
        if root.left:
            self.leftBoundary(root.left, res)
        elif root.right:
            self.leftBoundary(root.right, res)
        
    
    def rightBoundary(self, root, res):
        tmp = []
        curr = root
        while curr:
            if self.isLeaf(curr):
                break
            tmp.append(curr.data)
            if curr.right:
                curr = curr.right
            elif curr.left:
                curr = curr.left
        for i in range(len(tmp)-1,-1,-1):
            res.append(tmp[i])
        
    def leafTraversal(self, root, res):
        if self.isLeaf(root):
            res.append(root.data)
            return
        if root.left:
            self.leafTraversal(root.left, res)
        if root.right:
            self.leafTraversal(root.right, res)
        
    def boundaryTraversal(self, root):
        # code here
        if not root:
            return []
        res = [root.data]
        if self.isLeaf(root):
            return res
        
        self.leftBoundary(root.left, res)
        self.leafTraversal(root, res)
        self.rightBoundary(root.right, res)
        return res