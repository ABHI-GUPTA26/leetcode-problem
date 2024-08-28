class Solution {
public: int solve(vector<int>&nums,int k){
    if(k<0) return 0;
 int n=nums.size();
       int l=0,r=0;
       int sum=0;
       int cnt=0;
        while(r<n){
   sum+=nums[r];
        while(sum>k){
            sum =sum-nums[l];
            l++;
        }
        cnt+=r-l+1;
        r++;
        }
        return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {

           return solve(nums,goal)-solve(nums,goal-1);

    }
};