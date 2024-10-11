class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ;
        int n=nums.size();
        vector<int>ans(n,0);
        int cnt1=0;
        int cnt2=1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[cnt1]=nums[i];
                cnt1+=2;

            }else{
                ans[cnt2]=nums[i];
                cnt2+=2;
            }
        }
        return ans;
    }
};