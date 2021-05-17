//
// Created by dev on 5/16/21.
//
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1));

        for (int j = 1; j < n+1; ++j) {
            for (int i = 1; i <= j; ++i) {
                if (i == j) {
                    dp[i][j] = true;
                    ++count;
                } else if (j - i == 1 && s[i-1] == s[j-1]) {
                    dp[i][j] = true;
                    ++count;
                } else if (j - i > 1 && s[i-1] == s[j-1] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    ++count;
                }
            }
        }
        return count;

    }
};

