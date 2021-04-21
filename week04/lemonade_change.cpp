//
// Created by kurumi on 2021/4/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto c: bills) {
            if (c == 5) ++five;
            else if (c == 10) ++ten, --five;
            else if (ten > 0) --ten, --five;
            else five -= 3;
            if (five < 0) return false;
        }
        return true;
    }
};

int main() {
    vector<int> bills{10, 10};
    Solution sol;
    cout << sol.lemonadeChange(bills) << endl;
}

