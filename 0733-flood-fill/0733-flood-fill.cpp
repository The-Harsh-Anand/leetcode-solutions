class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color) {
        int scol = image[sr][sc];
        if(scol==color) return;
        image[sr][sc] = color;
        int m = image.size(), n = image[0].size();
        int i, j, row, col;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            sr = q.front().first;
            sc = q.front().second;

            q.pop();

            for (i = -1; i <= 1; i++) {
                for (j = -1; j <= 1; j++) {
                    if (abs(i) == abs(j))
                        continue;
                    row = abs(sr + i);
                    col = abs(sc + j);
                    if (row < m && col < n && image[row][col] == scol) {
                        image[row][col] = color;
                        q.push({row,col});
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int scol = image[sc][sr];
        bfs(image, sr, sc, color);
        return image;
    }
};