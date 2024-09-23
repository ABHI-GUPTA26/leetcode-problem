class Solution {
public: 
int solve(int row,int col,vector<vector<int>>& arr,int n,vector<vector<int>>&dp){
     if (row==n-1){
        return arr[row][col];
     }
     if(dp[row][col]!=-1) return dp[row][col]; 
      int downleft=arr[row][col]+solve(row+1,col+1,arr,n,dp);
      int down=arr[row][col]+solve(row+1,col,arr,n,dp);
      return  dp[row][col]=min(downleft,down);
}
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,arr,n,dp);
    }
};