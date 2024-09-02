class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        int n=g.size();
        int m=s.size();
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
         while(n!=0 &&m!=0){
              if(s[m-1]>=g[n-1]){
                cnt++;
                m--;
                n--;
              }else{
                n--;
              }
         }
         return cnt;
    }
};