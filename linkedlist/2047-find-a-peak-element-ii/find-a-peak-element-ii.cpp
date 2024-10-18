class Solution {
public: 
   int highest_row_value(vector<vector<int>>& mat,int n,int m,int col){
    int index=-1;
    int highestvalue=INT_MIN;
    for(int i=0;i<n;i++){
        if(mat[i][col]>highestvalue){
            highestvalue=mat[i][col];
            index=i;
        }
    }
    return index;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int rowindex=highest_row_value(mat,n,m,mid);
            int left= (mid>=1)?mat[rowindex][mid-1]:-1;
            int right=(mid<m-1)?mat[rowindex][mid+1]:-1;
            if(mat[rowindex][mid]>left&&mat[rowindex][mid]>right){
                return {rowindex,mid};
            }else if(mat[rowindex][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};