//
// Created by dev on 5/15/21.
//
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> cache = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int ret = 0;
        int last = 0;
        for (int i = s.length()-1; i >= 0; --i) {
            int value = cache.find(s[i])->second;
            if (value >= last) {
                ret += value;
            } else {
                ret -= value;
            }
            last = value;
        }
        return ret;
    }
};

