//
// Created by kurumi on 2021/4/21.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total_size = m * n;
        int left = 0, right = total_size - 1;
        while (left <= right) {
            int mid = (left+right) / 2;
            int x = mid / n;
            int y = mid % n;
            int val = matrix[x][y];
            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

