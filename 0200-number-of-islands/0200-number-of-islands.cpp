class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& isVis, int x, int y) {
        isVis[x][y] = 1;
        int m = isVis.size(), n = isVis[0].size(),dr,dc;
        for(dr=-1;dr<=1;dr++) {
            for(dc=-1;dc<=1;dc++) {
                if(abs(dc)==abs(dr)) continue;
                int row = abs(x+dr);
                int col = abs(y+dc);
                if(row<m && col<n && grid[row][col]=='1' && !isVis[row][col])
                        dfs(grid,isVis,row,col);
                
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size(),i,j;
        vector<vector<int>> isVis(m,vector<int>(n,0));
        int cnt = 0;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]=='1' && !isVis[i][j]) {
                    cnt++;
                    dfs(grid,isVis,i,j);
                }
            }
        }
        return cnt;
    }
};