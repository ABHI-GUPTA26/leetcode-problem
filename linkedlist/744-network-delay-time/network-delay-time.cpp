class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        time[k]=0;
        while(!q.empty()){
            int mintime=q.top().first;
             int node=q.top().second;
             q.pop();
             for(auto it:adj[node]){
                int adjnode=it.first;
                int adjtime=it.second;
                if(mintime+adjtime<time[adjnode]){
                    time[adjnode]=mintime+adjtime;
                    q.push({time[adjnode],adjnode});
                }
             }
        }
        int maxtime=0;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX){
                return -1;
            }
            maxtime=max(maxtime,time[i]);
        }
        return maxtime;
    }
};