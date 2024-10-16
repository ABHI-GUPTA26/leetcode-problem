class Solution {
public:
    int solve(vector<int>& prices,int idx,int n,int buy,vector<vector<int>>&dp){
       if(idx==n) return 0;      
        if(dp[idx][buy]!=-1)return dp[idx][buy];
         if(buy){
            return dp[idx][buy]= max((-prices[idx]+solve(prices,idx+1,n,0,dp)),(solve(prices,idx+1,n,1,dp)));

         }
         else{
            return  dp[idx][buy]=max((prices[idx]+solve(prices,idx+1,n,1,dp)),solve(prices,idx+1,n,0,dp));
         }
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
       return solve(prices,0,n,1,dp);
        
        
    }
};