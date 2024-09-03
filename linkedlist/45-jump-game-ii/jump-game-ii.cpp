class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,l=0,r=0;
    int n=nums.size();
    while(r<n-1){
        int farthest=0;
        for(int i=l;i<=r;i++){
            farthest=max(farthest,i+nums[i]);
        }
        jump=jump+1;
        l=r+1;
        r=farthest;
    }
    return jump;

    }
};