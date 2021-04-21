//
// Created by kurumi on 2021/4/21.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        int flag = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_pos < i) {
                flag = false;
                break;
            }
            max_pos = max(max_pos, i+nums[i]);
        }
        return flag;
    }
};

