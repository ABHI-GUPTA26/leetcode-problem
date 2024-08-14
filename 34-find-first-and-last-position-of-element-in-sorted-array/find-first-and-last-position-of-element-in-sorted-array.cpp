class Solution {
public:  
 int firstindex(vector<int>& nums, int target,int start,int end){
          while(start<=end){
              int mid=start+(end-start)/2;
              
              if(nums[mid]<target){
                 start=mid+1;
              }else{
                end=mid-1;
              }
          }
          return start;
}
 int lastindex(vector<int>& nums, int target,int start,int end){
          while(start<=end){
              int mid=start+(end-start)/2;
              
              if(nums[mid]<=target){
                 start=mid+1;
              }else{
                end=mid-1;
              }
          }
          return end;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
         if(n==0)return {-1,-1};
        int start=0;
        int end=n-1;
       
         int sindex=firstindex(nums,target,start,end);
         if( sindex>=n||nums[sindex]!=target) return {-1,-1};
         int lindex=lastindex(nums,target,start,end);
         if(lindex>=n||nums[lindex]!=target) return {-1,-1}; 
       
         return {sindex,lindex};

    }
};