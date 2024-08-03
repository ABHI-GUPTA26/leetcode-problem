class Solution {
    int mod=1e9+7;
public:  int solve(string &s,string &t,int idx1,int idx2,vector<vector<int>>&dp){
           if(idx2<0)return 1;
           if(idx1<0)return 0;
          if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
           if(s[idx1]==t[idx2]){
            return dp[idx1][idx2]= solve(s,t,idx1-1,idx2-1,dp)+solve(s,t,idx1-1,idx2,dp)%mod;
           }
           return dp[idx1][idx2]= solve(s,t,idx1-1,idx2,dp)%mod;
}
  
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int >(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod;
                } else {
                    dp[i][j] = dp[i - 1][j]%mod;
                }
            }
        }
        return dp[n][m];
    }


};