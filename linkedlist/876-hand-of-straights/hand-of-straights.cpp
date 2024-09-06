class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int n=hand.size();
         if(n%groupSize!=0) return false;
         sort(hand.begin(),hand.end());
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[hand[i]]==0){
                continue;
            }
            mp[hand[i]]--;
             int num=hand[i]+1;
             int cnt=groupSize-1;
             while(cnt--){
                if(mp[num]==0) return false;
                mp[num]--;
                num++;
                
             }
        }
        return true;

    }
};