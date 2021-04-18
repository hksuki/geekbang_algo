//
// Created by kurumi on 2021/4/18.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            int level_size = myQueue.size();
            ret.push_back(vector<int>());
            for (int i = 0; i != level_size; ++i) {
                TreeNode *tmp = myQueue.front();
                myQueue.pop();
                ret.back().push_back(tmp->val);
                if (tmp->left) myQueue.push(tmp->left);
                if (tmp->right) myQueue.push(tmp->right);
            }
        }
        return ret;
    }
};

int main() {

}

