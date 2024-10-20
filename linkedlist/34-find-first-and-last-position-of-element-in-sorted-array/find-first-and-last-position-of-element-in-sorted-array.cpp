class Solution {
public:
int solveceil(int x,vector<int>&arr){
               int n=arr.size();
        int start=0;
        int end=n-1;
         int index=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                index=mid;
            }
            if(arr[mid]<=x){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return index;
           }
           int solvefloor(int x,vector<int>&arr){
               int n=arr.size();
        int start=0;
        int end=n-1;
        int index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
              if(arr[mid]==x) {
                 index=mid;
              }
            if(arr[mid]<x){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return index;
           }
    vector<int> searchRange(vector<int>& arr, int x) {
            int n=arr.size();
        
        vector<int>ans;
        
        int indexfloor=solvefloor(x,arr);
        if(indexfloor==-1 ||arr[indexfloor]!=x){
            ans.push_back(-1);
        }else{
            ans.push_back(indexfloor);
        }
        int indexceil=solveceil(x,arr);
        if(indexceil==n ||arr[indexceil]!=x){
             ans.push_back(-1);
        }else{
            ans.push_back(indexceil);
        }
        return ans;
    }
};