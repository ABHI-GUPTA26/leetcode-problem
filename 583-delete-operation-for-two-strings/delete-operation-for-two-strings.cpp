class Solution {
public:
    int solve(string &word1 ,string &word2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1<0||idx2<0){
            return 0;
    
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];

        }
        if(word1[idx1]==word2[idx2]){
           return dp[idx1][idx2]=1+solve(word1,word2,idx1-1,idx2-1,dp);
        }
        return dp[idx1][idx2]=max(solve(word1,word2,idx1-1,idx2,dp),solve(word1,word2,idx1,idx2-1,dp));

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int clength=solve(word1,word2,n-1,m-1,dp);
        return n+m-2*clength;
    }
};