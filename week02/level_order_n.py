"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        queue = collections.deque()
        if not root:
            return []
        queue.append(root)
        ret = []
        while queue:
            level = []
            for _ in range(len(queue)):
                t = queue.popleft()
                level.append(t.val)
                queue.extend(t.children)
            ret.append(level)
        return ret[:]