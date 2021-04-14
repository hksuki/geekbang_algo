# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        ret = []
        p = root
        while p or len(stack) != 0:
            if not p:
                tmp = stack.pop()
                ret.append(tmp.val)
                p = tmp.right
            else:
                stack.append(p)
                p = p.left
        return ret[:]