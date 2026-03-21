from typing import List
def inorderTraversal(self, root) -> List[int]:
    curr = root
    res = []
    while curr:
        # if curr has a left child
        # find the ip
        if curr.left:
            IP = curr.left
            while IP.right and IP.right != curr:
                IP = IP.right
            if not IP.right:
                # create a pseudo link
                IP.right = curr
                curr = curr.left
            else:
                # print the curr, delete link and move to right
                res.append(curr.val)
                IP.right = None
                curr = curr.right
        else:
            res.append(curr.val)
            curr = curr.right
    return res