#define ll long long
class Solution {
public:
    struct State{
        long long dist;
        int node;
        int cnt;
        bool operator>(const State& other) const {
            return dist > other.dist;
        }
    };
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<State,vector<State>,greater<State>> pq;
        vector<int> best(n,k+1);
        pq.push({0,0,1});
        while(!pq.empty()) {
            auto [d, node, cnt]=pq.top();
            pq.pop();
            if(cnt>=best[node]) continue;
            if(node==n-1) return d;
            best[node]=cnt;
            for(auto [v,w]:adj[node]) {
                int c = labels[v]==labels[node]?cnt+1:1;
                if(c<=k && c<best[v]) pq.push({d+w,v,c});
            }
        }
        return -1;
    }
};