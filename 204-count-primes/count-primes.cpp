class Solution {
public:
     void solve(vector<int> & prime,int n){
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j=j+i){
                    prime[j]=0;
                }
            }
        }
     }
    int countPrimes(int n) {
        vector<int>prime(n+1,1);
        int cnt=0;
        solve(prime,n);
        for(int i=2;i<n;i++){
            if(prime[i]==1){
                cnt++;
            }
        }
        return cnt;

    }
};