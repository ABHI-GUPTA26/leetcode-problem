class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ind=0;
        int ans=1;
        int n=arr.size();
        int cnt=0;
        while(cnt!=k){
            if((ind<n&&ans<arr[ind])||ind>=n) cnt++;
            if(ind<n&&ans==arr[ind]) ind++;
            ans++;
        }
        return ans-1;
    }
};