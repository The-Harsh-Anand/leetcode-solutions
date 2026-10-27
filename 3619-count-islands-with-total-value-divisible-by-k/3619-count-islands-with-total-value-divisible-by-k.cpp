class Solution {
public:
    vector<int> dir={0,1,0,-1,0};
    int K;
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y,int& curr_sum) {
        int m=grid.size(),n=grid[0].size();
        int i;
        vis[x][y]=1;
        for(i=0;i<4;i++) {
            int r = abs(x+dir[i]);
            int c = abs(y+dir[i+1]);
            if(r<m && c<n && grid[r][c]!=0 && !vis[r][c]) {
                curr_sum = (curr_sum+grid[r][c])%K;
                dfs(grid,vis,r,c,curr_sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),i,j;
        K=k;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ctr=0;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]!=0 && !vis[i][j]) {
                    int curr_sum=grid[i][j];
                    dfs(grid,vis,i,j,curr_sum);
                    if(curr_sum%k==0) ctr++;
                }
            }
        }
        return ctr;
    }
};