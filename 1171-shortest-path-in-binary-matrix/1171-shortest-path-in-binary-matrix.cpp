class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int i, j, n = grid.size();

        if (grid[0][0] || grid[n-1][n-1])
            return -1;
        if (n == 1)
            return 1;

        vector<vector<int>> dist(n, vector<int>(n, 0));
        vector<vector<int>> dir = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1},
                                   {0, 1},   {1, 0},  {-1, 0}, {0, -1}};
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int d = q.front()[2];

            if(row==n-1 && col==n-1) break;
            q.pop();

            for (i = 0; i < 8; i++) {
                int r = abs(row + dir[i][0]);
                int c = abs(col + dir[i][1]);
                if (r < n && c < n && !grid[r][c] &&
                    (!dist[r][c] || d + 1 < dist[r][c])) {
                    dist[r][c] = d + 1;
                    q.push({r, c, d + 1});
                }
            }
        }
        return dist[n - 1][n - 1] == 0 ? -1 : dist[n - 1][n - 1];
    }
};