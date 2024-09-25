class Solution {
public: 
     int solve(vector<int>&coins,int idx,int k,vector<vector<int>>&dp){        if(idx==0){
          if(k%coins[idx]==0){
            return k/coins[idx];
          }else{
            return 1e9;
          }
     }
         if(dp[idx][k]!=-1)return dp[idx][k];
        int nontake=solve(coins,idx-1,k,dp);
        int take=1e9;
        if(coins[idx]<=k){
            take=1+solve(coins,idx,k-coins[idx],dp);
        }
        return dp[idx][k]=min(take,nontake);
     }
    int coinChange(vector<int>& coins, int k) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        int ans=solve(coins,n-1,k,dp);
        if(ans==1e9){
            return -1;
        }else{
             return ans;
        }
    }
};