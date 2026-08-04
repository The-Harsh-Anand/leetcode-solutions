class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int i,j,n=grid.size();

        if(grid[0][0]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;

        vector<vector<int>> dist(n,vector<int>(n,0));
        queue<vector<int>> q;
        q.push({0,0,1});
        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int d = q.front()[2];

            q.pop();

            for(i=-1;i<=1;i++) {
                for(j=-1;j<=1;j++) {
                    if(!(i|j)) continue;
                    int r = abs(row+i);
                    int c = abs(col+j);
                    if(r<n && c<n && !grid[r][c] && (!dist[r][c] || d+1 < dist[r][c])) {
                        dist[r][c]=d+1;
                        q.push({r,c,d+1});
                    }
                }
            }
        }
        return dist[n-1][n-1]==0?-1:dist[n-1][n-1];
    }
};