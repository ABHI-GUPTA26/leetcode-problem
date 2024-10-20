class Solution {
public:
    int solve(string &text1, string &text2, int idx1, int idx2, vector<vector<int>>& dp) {
        if (idx1 < 0 || idx2 < 0) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if (text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = 1 + solve(text1, text2, idx1 - 1, idx2 - 1, dp);
        }
        return dp[idx1][idx2] = max(solve(text1, text2, idx1 - 1, idx2, dp), solve(text1, text2, idx1, idx2 - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, n - 1, m - 1, dp);
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        return longestCommonSubsequence(s, str);
    }
};
