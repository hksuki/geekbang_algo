//
// Created by kurumi on 2021/4/18.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0, j = 0; i != g.size() && j != s.size(); ++j) {
            if (s[j] >= g[i]) {
                ++i;
                ++count;
            }
        }
        return count;
    }
};

int main() {
    vector<int> g{1,2,3};
    vector<int> s{1,1};
    Solution sol;
    cout << sol.findContentChildren(g,s) << endl;
}

