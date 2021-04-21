//
// Created by kurumi on 2021/4/21.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int, string>> q;
        unordered_set<string> word_set{wordList.begin(), wordList.end()};
        if (word_set.find(endWord) == word_set.end()) {
            return 0;
        }
        q.push(make_pair(1, beginWord));
        while (!q.empty()) {
            auto next = q.front();q.pop();
            if (next.second == endWord) {
                return next.first;
            }
            bool flag = false;
            for (int i = 0; i < beginWord.length(); ++i) {
                string tmp = next.second;
                for (int j = 0; j < 26; ++j) {
                    tmp[i] = 'a' + j;
                    if (word_set.find(tmp) != word_set.end()) {
                        word_set.erase(tmp);
                        q.push(make_pair(next.first+1, tmp));

                    }
                }
            }
        }
        return 0;
    }
};

