
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        stack, ret = [root,], []
        while stack:
            root = stack.pop()
            if not root.children:
                ret.append(root.val)
            else:
                ret.append(root.val)
                for c in root.children[::-1]:
                    stack.append(c)
        return ret[:]