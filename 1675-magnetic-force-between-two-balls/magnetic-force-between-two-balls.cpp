class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start=1;
        int end=(position.back()-position[0])/(m-1);
int ans=1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(canpossible(position,mid,m)){
                start=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;;
    }
    bool canpossible(vector<int>&position,int dist,int m){
        int cnt=1;
        int lastposition=position[0];
        int n=position.size();
        for(int i=1;i<n;i++){
            if(position[i]-lastposition>=dist){
                cnt++;
                lastposition=position[i];
            }
            if(cnt>=m)return true;
        }
        
        return false;
    }
};