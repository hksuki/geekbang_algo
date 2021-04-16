//
// Created by kurumi on 2021/4/16.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<int>> path_vec;
    vector<int> path;
    unordered_set<int> col;
    unordered_set<int> pie;
    unordered_set<int> na;

    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n);
        generate(n);
        return ret;
    }

    void dfs(int row, int n){
        if (row == n) {
            vector<int> tmp{path};
            path_vec.push_back(tmp);
            return;
        }
        for (int i = 0; i != n; ++i) {
            if (col.find(i) != col.end() || pie.find(i+row) != pie.end() || na.find(i-row) != pie.end()) {
                continue;
            }
            col.insert(i);
            pie.insert(i+row);
            na.insert(i-row);
            path.push_back(i);
            dfs(row+1, n);
            col.erase(i);
            pie.erase(i+row);
            na.erase(i-row);
            path.pop_back();
        }
        return;
    }

    void generate(int n) {
        for (int i = 0; i < path_vec.size(); ++i) {
            vector<string> tmp{};
            string t = "";
            for (int j = 0; j < n; ++j) {
                tmp.push_back(string(path_vec[i][j], '.')+"Q"+string(n-path_vec[i][j]-1, '.'));
            }
            ret.push_back(tmp);
        }
    }

};

int main() {
    vector<vector<string>> result;
    Solution sol;
    result = sol.solveNQueens(4);
    for (int i = 0; i != result.size(); ++i) {
        for (auto row : result[i]) {
            cout << row << endl;
        }
        cout << string(12, '*') << endl;
    }
}

