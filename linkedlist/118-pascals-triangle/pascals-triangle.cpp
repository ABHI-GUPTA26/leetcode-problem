class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n=numRows;

        if(n==0) return ans;
        vector<int>pre(1,1);
        ans.push_back(pre);
        for(int i=1;i<n;i++){
            vector<int>temp;
            for(int j=0;j<i+1;j++){
                if(j==0){
                    temp.push_back(1);
                }
                else if(j==i){
                    temp.push_back(1);
                }else{
                    temp.push_back(pre[j-1]+pre[j]);
                }
            }
            pre=temp;
            ans.push_back(temp);
        }
        return ans;
    }
};