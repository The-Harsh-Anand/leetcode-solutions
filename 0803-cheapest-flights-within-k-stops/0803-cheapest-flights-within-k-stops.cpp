class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto& it:flights)  adj[it[0]].push_back({it[1],it[2]});
        vector<int> dis(n,INT_MAX);
        queue<vector<int>> q;
        q.push({0,0,src});
        dis[src]=0;
        while(!q.empty()) {
            int dist = q.front()[1];
            int node = q.front()[2];
            int stop = q.front()[0];
            q.pop();
            if(stop>k) continue;
            for(auto& nei:adj[node]) {
                if(dist+nei[1] < dis[nei[0]] && stop<=k) {
                    dis[nei[0]] = dist+nei[1];
                    q.push({stop+1,dis[nei[0]],nei[0]});
                }
            }
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};