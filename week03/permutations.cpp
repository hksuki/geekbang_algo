//
// Created by kurumi on 2021/4/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> map;
        vector<vector<int>> ret;
        vector<int> path;
        dfs(map, nums, ret, path);
        return ret;
    }
    void dfs(unordered_set<int> &map, vector<int> &nums, vector<vector<int>> &ret, vector<int> &path) {
        if (path.size() == nums.size()) {
            vector<int> tmp{path};
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                continue;
            }
            map.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(map, nums, ret, path);
            path.pop_back();
            map.erase(nums[i]);
        }
        return;
    }
};

int main() {
    vector<int> nums = {
            1,2,3
    };
    Solution sol;
    vector<vector<int>> ret = sol.permute(nums);
    for (auto iter: ret) {
        for (auto val: iter) {
            cout << val << " ";
        }
        cout << endl;
    }
}

