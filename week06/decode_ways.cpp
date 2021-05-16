//
// Created by kurumi on 2021/5/16.
//
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> dp(s.length()+1);
        dp[1] = 1;
        dp[0] = 1;
        char last = 0;
        for (int i = 2; i < s.length()+1; ++i){
            int val = s[i-1] - '0';
            int val2 = (s[i-2] - '0')*10 + val;
            if (val >= 1 && val <= 9) dp[i] += dp[i-1];
            if (val2 >= 10 && val2 <= 26) dp[i] += dp[i-2];
        }
        return dp[s.length()];
    }
};
