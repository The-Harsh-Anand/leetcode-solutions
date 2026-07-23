class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node) {
        if(vis[node]!=0) return vis[node]==2;
        vis[node]=1;
        for(auto it: graph[node]) {
            if(!dfs(graph,vis,it)) return false;
        }
        vis[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size(),i;
        vector<int> ans,vis(n,0);
        for(i=0;i<n;i++) {
            if(dfs(graph,vis,i)) ans.push_back(i);
        }
        return ans;
    }
};