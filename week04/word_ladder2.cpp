//
// Created by kurumi on 2021/4/21.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set{wordList.begin(), wordList.end()};
        vector<vector<string>> ret;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        int min_level = INT_MAX;
        if (word_set.find(endWord) == word_set.end()) {
            return vector<vector<string>>();
        }
        unordered_set<string> visited;
        while (!q.empty() && level < min_level) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                vector<string> path = q.front();
                q.pop();
                string last = path.back();
                for (int j = 0; j < last.length(); ++j) {
                    string n = last;
                    for (int k = 0; k < 26; ++k) {
                        n[j] = 'a' + k;
                        if (word_set.find(n) != word_set.end()) {
                            vector<string> new_path{path};
                            new_path.push_back(n);
                            visited.insert(n);
                            if (n == endWord) {
                                ret.push_back(new_path);
                                min_level = level;
                            } else {
                                q.push(new_path);
                            }
                        }
                    }
                }
            }
            for (auto v: visited) {
                word_set.erase(v);
            }
            visited.clear();
            ++level;
        }
        return ret;
    }
};

