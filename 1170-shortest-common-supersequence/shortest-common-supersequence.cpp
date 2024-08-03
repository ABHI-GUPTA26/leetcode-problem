class Solution {
public:
    int solve(string &word1, string &word2, int idx1, int idx2, vector<vector<int>>& dp) {
        if (idx1 == 0 || idx2 == 0) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        if (word1[idx1 - 1] == word2[idx2 - 1]) {
            return dp[idx1][idx2] = 1 + solve(word1, word2, idx1 - 1, idx2 - 1, dp);
        }
        return dp[idx1][idx2] = max(solve(word1, word2, idx1 - 1, idx2, dp), solve(word1, word2, idx1, idx2 - 1, dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        solve(str1, str2, n, m, dp);

        string result = "";
        int i = n, j = m;
        
        // Reconstruct the shortest common supersequence
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters from str1 or str2
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }

        // Since we constructed result backwards, reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};
