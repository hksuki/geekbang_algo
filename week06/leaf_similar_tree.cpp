//
// Created by dev on 5/10/21.
//
#include <vector>

using namespace std;

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
    void dfs(TreeNode *root, vector<int> &path) {
        if (!root->left && !root->right) {
            path.push_back(root->val);
            return;
        }
        if (root->left) {
            dfs(root->left, path);
        }
        if (root->right) {
            dfs(root->right, path);
        }
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> path1;
        vector<int> path2;
        dfs(root1, path1);
        dfs(root2, path2);
        if (path1 == path2) return true;
        else return false;
    }
};

