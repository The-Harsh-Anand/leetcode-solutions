class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;

        vector<vector<vector<int>>> adj(n);
        for(auto& it:roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (dis > dist[node]) continue;

            for(auto& it:adj[node]) {
                if(dis+it[1] < dist[it[0]]) {
                    dist[it[0]] = dis+it[1];
                    pq.push({dist[it[0]],it[0]});

                    ways[it[0]] = ways[node]%mod;

                } else if(dis+it[1] == dist[it[0]]) {
                    ways[it[0]] = (ways[it[0]]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};