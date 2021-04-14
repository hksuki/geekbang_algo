class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # def build(s1, e1, s2, e2):
        #     if s1 > e1:
        #         return None
        #     node = TreeNode(preorder[s1])
        #     r = index[preorder[s1]]
        #     left_size = r - s2
        #     node.left = build(s1+1,s1+left_size, s2, r - 1)
        #     node.right = build(s1+left_size+1, e1, r+1, e2)
        #     return node

        # index = {e:i for i, e in enumerate(inorder)}
        # return build(0, len(inorder)-1, 0, len(inorder)-1)
        def build(start, end):
            if start > end:
                return None
            root_val = next(pre_iter)
            node = TreeNode(root_val)
            mid = index[root_val]
            node.left = build(start, mid-1)
            node.right = build(mid+1, end)
            return node
        index = {e:i for i, e in enumerate(inorder)}
        pre_iter = iter(preorder)
        return build(0, len(inorder)-1)
