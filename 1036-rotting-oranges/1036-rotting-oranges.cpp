class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q,
            int& time, vector<pair<int, int>>& dir) {
        //MULTISOURCE BFS
        int m = grid.size(), n = grid[0].size(), i, j;
        while (!q.empty()) {
            int l = 0,sz = q.size();
            bool rotten = false;
            while(sz--) {
                int r = q.front().first, c = q.front().second;
                for (j = 0; j < 4; j++) {
                    int row = abs(r + dir[j].first);
                    int col = abs(c + dir[j].second);
                    if (row < m && col < n && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        rotten = true;
                    }
                }
                q.pop();
            }
            if(rotten) time++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int i, j, m = grid.size(), n = grid[0].size();
        int time = 0;
        queue<pair<int,int>> q;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 2)  
                    q.push({i, j});
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        bfs(grid, q, time, dir);
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};