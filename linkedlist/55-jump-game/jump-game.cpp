class Solution {
public:   
bool solve(vector<int>&nums,int idx,int n,vector<int>&dp){
    if(idx==n-1){
        return true;
    } if(nums[idx]==0){
        return false;
    }
      if(dp[idx]!=-1){
        return dp[idx];
      }
    int maxjump=min(idx+nums[idx],n-1);
    for(int i=idx+1;i<=maxjump;i++){
        if(solve(nums,i,n,dp)){
            return dp[idx]= true;
        }

       

    }
    return dp[idx]= false;
    
      
} 
    bool canJump(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp(n,-1);
       return  solve(nums,0,n,dp);
    }
};