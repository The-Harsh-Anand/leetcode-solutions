class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<int> dir = {0, 1, 0, -1, 0};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int r = pq.top()[1];
            int c = pq.top()[2];
            int eff = pq.top()[0];
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int dr = abs(r + dir[i]);
                int dc = abs(c + dir[i + 1]);
                if (dr < m && dc < n) {
                    int ef = max(eff, abs(heights[dr][dc] - heights[r][c]));
                    if (ef < dist[dr][dc]) {
                        pq.push({ef, dr, dc});
                        dist[dr][dc] = ef;
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};