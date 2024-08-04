class Solution {
public:       
  int min_operation(string &str1,string &str2,int idx1,int idx2,vector<vector<int>>&dp){
           if(idx2==0){
           return idx1;
           }
           if(idx1==0){
            return idx2;
           }
           if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
          
          

        if(str1[idx1-1]==str2[idx2-1]){
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
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return min_operation(word1,word2,n,m,dp);

        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
           for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int insert=dp[i][j-1];
                    int deleted=dp[i-1][j];
                    int replace=dp[i-1][j-1];
                    dp[i][j]=1+min(insert,min(deleted,replace));
                }
            }
           }
           return dp[n][m];
    }
};