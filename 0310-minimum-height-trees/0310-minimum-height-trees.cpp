class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(!edges.size()) return{0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int i;
        queue<int> q;
        for(i=0;i<n;i++) {
            if(degree[i]==1) q.push(i);
        }
        int remNodes=n;
        while(remNodes>2) {
            int sz = q.size();
            remNodes-=sz;
            while(sz--) {
                int node = q.front();
                q.pop();
                for(auto it:adj[node]) {
                    degree[it]--;
                    if(degree[it]==1) {
                        q.push(it);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};