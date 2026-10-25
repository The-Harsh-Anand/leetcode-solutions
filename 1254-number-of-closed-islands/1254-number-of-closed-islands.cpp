class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    void dfs(vector<vector<int>>& grid, int x, int y, int flag) {
        if(flag==0)  grid[x][y]=1;
        else grid[x][y]=2;
        int i,m=grid.size(),n=grid[0].size();
        for(i=0;i<4;i++) {
            int r = abs(x+dir[i]);
            int c = abs(y+dir[i+1]);
            if(r<m && c<n && grid[r][c]==0)
                dfs(grid,r,c,flag);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ctr=0,m=grid.size(),n=grid[0].size();
        int i,j;
        for(i=0;i<m;i++) {
            if(grid[i][0]==0) dfs(grid,i,0,0);
            if(grid[i][n-1]==0) dfs(grid,i,n-1,0);
        }
        for(j=0;j<n;j++) {
            if(grid[0][j]==0) dfs(grid,0,j,0);
            if(grid[m-1][j]==0) dfs(grid,m-1,j,0);
        }
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    ctr++;
                    dfs(grid,i,j,1);
                }
            }
        }
        return ctr;
    }

};