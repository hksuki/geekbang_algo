//
// Created by kurumi on 2021/4/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return d_and_c(nums, 0, nums.size()-1);
    }

    int d_and_c(vector<int> &nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int l = d_and_c(nums, left, mid);
        int r = d_and_c(nums, mid+1, right);
        if (l == r) {
            return l;
        }
        int count_l = 0;
        int count_r = 0;
        for (int i = left; i < right+1; ++i) {
            if (nums[i] == l) {
                ++count_l;
            }
            if (nums[i] == r) {
                ++count_r;
            }
        }
        if (count_l > count_r) {
            return l;
        } else {
            return r;
        }
    }
};

int main() {
    vector<int> nums = {
            2,4,5,1,2,4,2,2,2,0,2
    };
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}

