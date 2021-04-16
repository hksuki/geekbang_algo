//
// Created by kurumi on 2021/4/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(0, path, ret, nums);
        return ret;

    }

    void dfs(int cur, vector<int> &path, vector<vector<int>> &ret, const vector<int>& nums) {
        if (cur == nums.size()) {
            vector<int> tmp{path};
            ret.push_back(tmp);
            return;
        }
        path.push_back(nums[cur]);
        dfs(cur+1, path, ret, nums);
        path.pop_back();
        dfs(cur+1, path, ret, nums);
        return;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {
            2,5,9,10
    };
    for (auto i : sol.subsets(nums)) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

