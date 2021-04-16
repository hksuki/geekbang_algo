//
// Created by kurumi on 2021/4/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        bool used[nums.size()];
        for (int i = 0; i != nums.size(); ++i) {
            used[i] = false;
        }
        sort(nums.begin(), nums.end());
        dfs(ret, nums, path, used);
        return ret;
    }

    void dfs(vector<vector<int>> &ret, const vector<int> &nums, vector<int> &path, bool *used) {
        if (path.size() == nums.size()) {
            vector<int> temp{path};
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (used[i] == true || (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(ret, nums, path, used);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
};

int main() {
    vector<int> nums = {
            1,1,2,2
    };
    Solution sol;
    vector<vector<int>> ret = sol.permuteUnique(nums);
    for (auto iter: ret) {
        for (auto val: iter) {
            cout << val << " ";
        }
        cout << endl;
    }
}

