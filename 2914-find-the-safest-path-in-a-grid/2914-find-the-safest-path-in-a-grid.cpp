class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool possibility(vector<vector<int>>& safe, int lim) {
        int n = safe.size(), i;
        if (safe[0][0] < lim)
            return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));

        // BFS Again
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1)
                return true;
            for (i = 0; i < 4; i++) {
                int r = abs(row + dir[i][0]);
                int c = abs(col + dir[i][1]);

                if (r < n && c < n && !vis[r][c] && safe[r][c] >= lim) {
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), i, j;

        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        queue<vector<int>> q;
        vector<vector<int>> safe(n, vector<int>(n, -1));

        // MULTISOURCE BFS
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                    safe[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int sz = q.size();
            int row = q.front()[0];
            int col = q.front()[1];
            int md = q.front()[2];
            q.pop();
            for (i = 0; i < 4; i++) {
                int r = abs(row + dir[i][0]);
                int c = abs(col + dir[i][1]);
                if (r < n && c < n) {
                    if (safe[r][c] == -1) {
                        safe[r][c] = md + 1;
                        q.push({r, c, safe[r][c]});
                    } else
                        safe[r][c] = min(safe[r][c], md + 1);
                }
            }
        }

        int l = 0, r = safe[0][0], ans = 0, m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (possibility(safe, m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};