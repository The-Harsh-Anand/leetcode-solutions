class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& sus, int node) {
        sus[node]=-1;
        for(auto it:adj[node]) {
            if(!sus[it]) dfs(adj,sus,it);
        }
    }
    void helper(vector<vector<int>>& adj, vector<int>& sus, int node) {
        sus[node]=1;
        for(auto it:adj[node]) {
            if(!sus[it] || sus[it]==-1) {
                helper(adj,sus,it);
            } 
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n);
        vector<int> sus(n,0);
        int i,flag=0;
        for(i=0;i<inv.size();i++) {
            adj[inv[i][0]].push_back(inv[i][1]);
        }
        dfs(adj,sus,k);
        vector<int> ans;

        for(auto it:inv) {
            if(!sus[it[0]] && sus[it[1]]) {
                for(i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        for(i=0;i<n;i++) {
            if(!sus[i]) ans.push_back(i);
        }
        return ans;
    }
};