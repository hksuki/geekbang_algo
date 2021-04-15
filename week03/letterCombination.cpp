//
// Created by kurumi on 2021/4/15.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.length() == 0) {
            return ret;
        }
        unordered_map<char, string> map_list {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        generate(ret, digits, map_list, 0, "");
        return ret;
    }
    void generate(vector<string> &ret, const string &digits, const unordered_map<char, string> &map_list, int i, string r) {
        if (i == digits.length()) {
            ret.push_back(r);
            return;
        }
        string tmp = map_list.find(digits[i])->second;
        for (auto c : tmp) {
            generate(ret, digits, map_list, i+1, r+c);
        }
        return;
    }
};

int main() {
    Solution s;
    for (auto str: s.letterCombinations("345")) {
        cout << str << endl;
    }
}

