//
// Created by dev on 5/17/21.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> x_info;
    pair<int, int> y_info;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, 1);
        if (x_info.first == y_info.first && x_info.second != y_info.second) {
            return true;
        }
        return false;
    }

    void dfs(TreeNode *root, int x, int y, int parent, int level) {
        if (!root) {
            return;
        }
        if (root->val == x) {
            x_info.first = level;
            x_info.second = parent;
        }
        if (root->val == y) {
            y_info.first = level;
            y_info.second = parent;
        }
        dfs(root->left, x, y, root->val, level+1);
        dfs(root->right, x, y, root->val, level+1);
        return;
    }
};

