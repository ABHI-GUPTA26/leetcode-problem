class Solution {
public:       
  int min_operation(string &str1,string &str2,int idx1,int idx2,vector<vector<int>>&dp){
           if(idx2<0){
           return idx1+1;
           }
           if(idx1<0){
            return idx2+1;
           }
           if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
          
          

        if(str1[idx1]==str2[idx2]){
            return dp[idx1][idx2]= min_operation(str1,str2,idx1-1,idx2-1,dp);
        }
        int insert=min_operation(str1,str2,idx1,idx2-1,dp);
        int deleted=min_operation(str1,str2,idx1-1,idx2,dp);
        int replace=min_operation(str1,str2,idx1-1,idx2-1,dp);
        return dp[idx1][idx2]=1+min(insert,min(deleted,replace));
  }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
        return min_operation(word1,word2,n-1,m-1,dp);

    }
};