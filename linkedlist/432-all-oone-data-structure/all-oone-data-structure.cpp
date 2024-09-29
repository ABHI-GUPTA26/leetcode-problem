class AllOne {
public:
     map<string,int>mp;
     set<pair<int,string>>st;
    AllOne() {
        mp.clear();
       // set.clear();
    }
    
    void inc(string key) {
        if(mp.find(key)!=mp.end()){
           int n=mp[key];
           mp[key]++;
           st.erase({n,key});
           st.insert({n+1,key});
        }else{
            mp[key]=1;
            st.insert({1,key});
        }
        
    }
    
    void dec(string key) {
        int n=mp[key];
        if(n-1==0){
        mp.erase(key);
        st.erase({n,key});}
        else{
            mp[key]--;
            st.erase({n,key});
            st.insert({n-1,key});
        }
    }
    
    string getMaxKey() {
        if(st.size()==0){
            return "";
        }else{
            string str=st.rbegin()->second;
            return str;
        }
        
    }
    
    string getMinKey() {
        if(st.size()==0){
            return "";
        }else{
            string str=st.begin()->second;
            return str;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */