class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<int>pq;
        for( auto it=mp.begin();it!=mp.end();it++){

            pq.push(it->second);
        }
        int time=0;
        while(!pq.empty()){
          vector<int>temp;
          for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int it=pq.top();
                pq.pop();
                it--;
                temp.push_back(it);
            }}
            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
               time+=temp.size();
            }else{
                time+=n+1;
            }
          
        }
        return time;
    }
};