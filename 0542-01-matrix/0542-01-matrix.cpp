class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),i,j;
        queue<vector<int>> q;
        vector<vector<int>> res(m,vector<int>(n,0)),vis(m,vector<int>(n,0));
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(!mat[i][j]) {
                    q.push({i,j,0});
                    vis[i][j] = 1;
                    res[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int dist = q.front()[2];
            q.pop();
            res[row][col] = dist;
            for(i=0;i<4;i++) {
                int r = abs(row+dir[i][0]);
                int c = abs(col+dir[i][1]);
                if(r<m && c<n && !vis[r][c]) {
                    vis[r][c] = 1;
                    q.push({r,c,dist+1});
                }
            }
        }
        return res;
    }
};