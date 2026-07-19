class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<vector<int>> adj(numCourses);
        int i;
        for(auto i:pr) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(numCourses,0), path(numCourses,0);
        for(i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(dfs(adj,vis,i,path)) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int src, vector<int>& path) {
        vis[src] = path[src] = 1;
        int i;
        for(auto i:adj[src]) {
            if(!vis[i]) {
                if(dfs(adj,vis,i,path)) return true;
            } else if(path[i]){
                return true;
            }
        }
        path[src] = 0;
        return false;
    }
};