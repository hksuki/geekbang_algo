//
// Created by kurumi on 2021/4/20.
//
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] < nums[mid] && nums[left] <= target && nums[mid] > target ||
                nums[left] > nums[mid] && (target >= nums[left] || target < nums[mid])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution sol;
    std::cout << sol.search(nums, target) << std::endl;
}

