//
// Created by kurumi on 2021/4/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(n, k, 0, path, result);
        return result;

    }

    void dfs(int n, int k, int start, vector<int> &path, vector<vector<int>> &result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        if (start == n || path.size() + n - start < k) {
            return;
        }
        for (auto i = start; i != n; ++i) {
            path.push_back(i+1);
            dfs(n, k, i+1, path, result);
            path.pop_back();
        }
        return;
    }
};

int main() {
    Solution sol;
    for (auto iter: sol.combine(4,2)) {
        cout << iter[0] << "," << iter[1] << endl;
    }
}

