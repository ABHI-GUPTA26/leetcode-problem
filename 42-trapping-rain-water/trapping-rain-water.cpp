

class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
        vector<int>premax(n);
        vector<int>suffmax(n);
        int premaxi=0;
        
        for(int i=0;i<n;i++){
            premaxi=max(premaxi,height[i]);
            premax[i]=premaxi;
        }
        int suffmaxi=0;

        for(int i=n-1;i>=0;i--){
          suffmaxi=max(suffmaxi,height[i]);
          suffmax[i]=suffmaxi;
        }
    

        int total=0;
        for(int i=0;i<n;i++){
            if(height[i]<premax[i]&&height[i]<suffmax[i]){
                total+=min(premax[i],suffmax[i])-height[i];
            }
        }
        return total;
    }
};