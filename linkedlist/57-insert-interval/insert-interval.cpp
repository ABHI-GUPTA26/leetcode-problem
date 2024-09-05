class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>>ans;
            vector<vector<int>>left;
            vector<vector<int>>right;
            int start=newInterval[0];
            int end=newInterval[1];
            for(auto it:intervals){
                if(it[1]<start){
                left.push_back(it);
                }
                else if(it[0]>end){
                    right.push_back(it);
                }
                else{
                    start=min(start,it[0]);
                    end=max(end,it[1]);
                    
                }
            }
            ans.insert(ans.end(),left.begin(),left.end());

            ans.push_back({start,end});
            ans.insert(ans.end(),right.begin(),right.end());
            return ans;
    }
};