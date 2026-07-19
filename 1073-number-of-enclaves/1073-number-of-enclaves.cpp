class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>&  mat, int row, int col,int& count) {
        int m=mat.size(),n=mat[0].size(),i;
        mat[row][col]=2;
        count++;
        for(i=0;i<4;i++) {
            int r = abs(row+dir[i][0]);
            int c = abs(col+dir[i][1]);
            if(r<m && c<n && mat[r][c]==1) {
                dfs(mat,r,c,count);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0,sea=0,i,j,m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(grid.begin(),grid.end());
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if((i==0 || j==0 || i==m-1 || j==n-1) && vis[i][j]==1) 
                    dfs(vis,i,j,count);
                if(vis[i][j]==0) sea++;
            }
        }
        return m*n-sea-count;
    }
};