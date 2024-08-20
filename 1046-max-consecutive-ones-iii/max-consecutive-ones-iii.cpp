class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int maxsize=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt++;
           if(cnt>k){
            while(cnt>k){
                if(nums[start]==0){
                    cnt--;

                }
                start++;
                
            }
             
           }
            maxsize=max(maxsize,i-start+1);
        }
        return maxsize;
    }
};