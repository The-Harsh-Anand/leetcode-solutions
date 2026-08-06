class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        int i;
        for(auto& it:times) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> time(n+1,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,k});
        time[k] = 0;

        while(!pq.empty()) {
            int node = pq.top()[1];
            int t = pq.top()[0];
            pq.pop();

            if(t>time[node]) continue;
            
            for(auto& it:adj[node]) {
                if(t+it[1]<time[it[0]]) {
                    time[it[0]] = t+it[1];
                    pq.push({time[it[0]],it[0]});
                }
            }
        }
        int total=0;
        for(i=1;i<=n;i++) {
            if(time[i]==INT_MAX) return -1;
            else total = max(time[i],total);
        }
        return total;
    }
};