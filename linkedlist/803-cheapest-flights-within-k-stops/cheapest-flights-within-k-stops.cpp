class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create adjacency list
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // Initialize distance vector
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // Use queue for BFS: {stops, node, cost}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if (stops > k) continue;
            
            for(auto it : adj[node]) {
                int nextNode = it.first;
                int weight = it.second;
                
                if (cost + weight < dist[nextNode]) {
                    dist[nextNode] = cost + weight;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
