class Solution {
private:
    struct st {
        int row, col, mask, eng;
    };

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int total = 0, sr = 0, sc = 0, i, j;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = total++;
                }
            }
        }

        int masks = 1 << total; // all the litters represented in bits
        int fullMask = masks - 1;

        vector<int> bestEng(m * n * masks, -1);
        int dir[] = {0, -1, 0, 1, 0};
        queue<st> q; // q{start_row, start_col, collected_litter, curr_energy}
        q.push({sr, sc, 0, energy});
        bestEng[(sr * n + sc) * masks] = energy;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, eng] = q.front();
                q.pop();

                if (mask == fullMask)
                    return steps;
                if (eng == 0)
                    continue;

                for (i = 0; i < 4; i++) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int neng = eng - 1;
                    int nMask = mask;

                    if (classroom[nr][nc] == 'L')
                        nMask = nMask | (1 << id[nr][nc]);
                    else if (classroom[nr][nc] == 'R')
                        neng = energy;

                    int idx = (nr * n + nc) * masks + nMask;
                    if (bestEng[idx] >= neng)
                        continue;

                    bestEng[idx] = neng;
                    q.push({nr, nc, nMask, neng});
                }
            }
            steps++;
        }
        return -1;
    }
};