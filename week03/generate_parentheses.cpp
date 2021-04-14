//
// Created by kurumi on 2021/4/13.
//
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        _generate(0, 0, n, "");
        return this->result;
    }

    void _generate(int left, int right, int n, std::string s) {
        if (left == n and right == n) {
            result.push_back(s);
            return;
        }
        if (left < n) {
            _generate(left+1, right, n, s+"(");
        }
        if (right < left) {
            _generate(left, right+1, n, s+")");
        }
        return;
    }
private:
    std::vector<std::string> result;
};

int main() {
    Solution s;
    for (auto i: s.generateParenthesis(3)) {
        std::cout << i << ",";
    }
}

