//
// Created by kurumi on 2021/4/21.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int max_pos = 0;
        int count = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            max_pos = max(max_pos, nums[i]+i);
            if (i == end) {
                end = max_pos;
                ++count;
            }
        }
        return count;
    }
};

