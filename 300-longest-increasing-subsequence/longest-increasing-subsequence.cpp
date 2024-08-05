class Solution {
public:

    int solve(vector<int>&nums,int idx,int pre_idx,int n,vector<vector<int>>&dp){
          if(idx==n) return 0;
            if(dp[idx][pre_idx+1]!=-1)return dp[idx][pre_idx+1];
          int ntake=0+solve(nums,idx+1,pre_idx,n,dp);
          
          if(pre_idx==-1||nums[idx]>nums[pre_idx]){
            int take=1+solve(nums,idx+1,idx,n,dp);
            return dp[idx][pre_idx+1]= max(take,ntake);
          }
          return dp[idx][pre_idx+1]= ntake;
    }
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
         return solve(nums,0,-1,n,dp);
    }
};