# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        serial_str = ""

        def dfs(root):
            if not root:
                return "N,"
            ret = ""
            ret += (str(root.val) + ",")
            ret += dfs(root.left)
            ret += dfs(root.right)
            return ret

        ret = dfs(root)
        return ret;

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        def dfs(data_list):
            root_val = next(data_list)
            if root_val == "N":
                return None
            node = TreeNode(root_val)
            node.left = dfs(data_list)
            node.right = dfs(data_list)
            return node

        root = None
        data_list = iter(data.split(",")[:-1])
        root = dfs(data_list)
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))