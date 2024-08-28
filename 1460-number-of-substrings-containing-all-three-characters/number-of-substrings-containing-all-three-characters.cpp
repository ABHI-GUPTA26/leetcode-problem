class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
    
        int cnt=0;
        
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp.size()==3){
                 
               while(mp.size()==3){
                 cnt+=n-i;
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
                 
               }

            
            }
        }
        return cnt;
    }
};