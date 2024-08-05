class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);        
        vector<int>cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[i]>nums[pre]&&dp[pre]+1>dp[i]){
                    dp[i]=1+dp[pre];
                    cnt[i]=cnt[pre];
                }else if(nums[i]>nums[pre]&&dp[pre]+1==dp[i]){
                    cnt[i]+=cnt[pre];
                }
            }
            maxi=max(maxi,dp[i]);
        }
int lis_count=0;
        for(int i=0;i<n;i++){
          if(dp[i]==maxi){
            lis_count+=cnt[i];
          }
        }
        return lis_count;
    }
};