class Solution {
public:   int largestsum(vector<int>&nums,int k){
      int cnt=1;
      int n=nums.size();
      int subarraysum=0;
      for(int i=0;i<n;i++){
        if(subarraysum+nums[i]<=k){
            subarraysum+=nums[i];
        }else{
            subarraysum=nums[i];
            cnt++;
        }
      }
      return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        while(start<=end){
            int mid=start+(end-start)/2;
            int student=largestsum(nums,mid);
            if(student>k){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return start;
    }
};