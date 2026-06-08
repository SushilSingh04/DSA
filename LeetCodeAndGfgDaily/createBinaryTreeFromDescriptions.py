from typing import List, Optional
# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from collections import defaultdict

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        parent_mp = defaultdict(lambda: [-1,-1])
        child_mp = {}

        for [parent, child, isLeft] in descriptions:
            parent_mp[parent][1-isLeft] = child
            child_mp[child] = parent
        
        for node_val in parent_mp.keys():
            if node_val not in child_mp:
                root_val = node_val
                break

        def build_tree(node_val):
            if root_val == -1:
                return None
            node = TreeNode(node_val)
            if node_val in parent_mp:
                left_node_val = parent_mp[node_val][0]
                right_node_val = parent_mp[node_val][1]

                if left_node_val != -1:
                    node.left = build_tree(left_node_val)
                if right_node_val != -1:
                    node.right = build_tree(right_node_val)
            
            return node
        
        return build_tree(root_val)
                 
        