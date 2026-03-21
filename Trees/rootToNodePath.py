from typing import List

class TreeNode:   
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def pathInATree(root: TreeNode, x: int) -> List[int]:
    # Write your code here.
    currPath = []
    helper(root, currPath, x)
    return currPath

def helper(root, currPath, x):
    if not root:
        return False

    currPath.append(root.data)
    
    if helper(root.left, currPath, x) or helper(root.right, currPath, x):
        return True
    # These two calls can be interchanged in positions
    if root.data == x:
        return True
    currPath.pop()
    return False