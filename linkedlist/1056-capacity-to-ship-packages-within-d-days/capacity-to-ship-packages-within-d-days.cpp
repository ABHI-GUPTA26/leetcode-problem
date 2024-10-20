class Solution {
public:   
      bool solve(vector<int>& weights, int days,int minweights){
          int n=weights.size();
          int sum=0;
          int cnt=1;
          for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>minweights){
                cnt++;
                sum=weights[i];
            } 
          }
          if(cnt<=days){
            return true;
          }else{
            return  false;
          }
      }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        
        int start=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=weights[i];
        }
        int end=sum;

        while(start<end){
            int mid=start+(end-start)/2;
            if(solve(weights,days,mid)){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        return start;
        
    }
};