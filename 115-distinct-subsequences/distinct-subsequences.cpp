class Solution {
public:  int solve(string &s,string &t,int idx1,int idx2,vector<vector<int>>&dp){
           if(idx2<0)return 1;
           if(idx1<0)return 0;
          if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
           if(s[idx1]==t[idx2]){
            return dp[idx1][idx2]= solve(s,t,idx1-1,idx2-1,dp)+solve(s,t,idx1-1,idx2,dp);
           }
           return dp[idx1][idx2]= solve(s,t,idx1-1,idx2,dp);
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};