class Solution {
public:
    bool match(string &str1, string &str2, int idx1, int idx2, vector<vector<int>> &dp) {
        if (idx1 < 0 && idx2 < 0) return true;
        if (idx1 < 0) return false;
        if (idx2 < 0) {
            while (idx1 >= 0) {
                if (str1[idx1] != '*') {
                    return false;
                }
                idx1--;
            }
            return true;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        if (str1[idx1] == str2[idx2] || str1[idx1] == '?') {
            return dp[idx1][idx2] = match(str1, str2, idx1 - 1, idx2 - 1, dp);
        } else if (str1[idx1] == '*') {
            return dp[idx1][idx2] = match(str1, str2, idx1 - 1, idx2, dp) || match(str1, str2, idx1, idx2 - 1, dp);
        } else {
            return dp[idx1][idx2] = false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return match(p, s, n - 1, m - 1, dp);
    }
};

 