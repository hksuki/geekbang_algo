//
// Created by dev on 5/16/21.
//
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        int max_val = 0;
        for (int i = 2; i < n + 1; ++i) {
            if (s[i-1] == ')') {
                if (s[i-2] == '(') {
                    dp[i] = dp[i-2] + 2;
                } else {
                    if (dp[i-1] > 0 && i-dp[i-1]-2 >= 0 && s[i-dp[i-1]-2] == '(') {
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    }
                }
            }
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};

