class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(),i;
        vector<int> vis(n,0);
        //colors used 1 and -1
        for(i=0;i<n;i++) {
            if(!vis[i]) {
                if(!dfs(graph, vis, i, -1, 1)) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int parent, int col) {
        vis[node] = col*-1;
        for(auto x:graph[node]) {
            if(x==parent) continue;
            else if(!vis[x]) {
                if(!dfs(graph, vis, x, node, col*-1)) return false;
            } else if(vis[x]==vis[node]) return false;
        }
        return true;
    }
};