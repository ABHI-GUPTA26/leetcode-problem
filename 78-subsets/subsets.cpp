class Solution {
public:
void solve(vector<int>&nums,int index,vector<int>&output,vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    solve(nums,index+1,output,ans);
    int element=nums[index];
    output.push_back(element);
    solve(nums,index+1,output,ans);
    output.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
       // vector<int>output;
       // int index=0;

        // this is the recursivw approch 
       // solve(nums,index,output,ans);
        //return ans;
///      now this is the bit basking approach
     int n=nums.size();
     int subsetno=1<<n;
     for(int i=0;i<subsetno;i++){
        vector<int>output;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                output.push_back(nums[j]);
            }
        }
        ans.push_back(output);

     }
     return ans;

    }
};