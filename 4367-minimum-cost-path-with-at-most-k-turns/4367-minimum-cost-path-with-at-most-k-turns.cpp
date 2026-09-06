typedef long long ll;
class Solution {
public:
    struct State {
        ll cost;
        int r,c;
        int turns;
        int dir;

        bool operator>(const State& s) const {
            return cost>s.cost;
        }
    };
    
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),d,i,j;
        const ll INF = 1e18;
        vector<vector<vector<array<ll,4>>>> dist(m, vector<vector<array<ll,4>>>(n, vector<array<ll,4>>(k+1, {INF,INF,INF,INF})));
        priority_queue<State, vector<State>, greater<State>> pq;

        int dir[] = {0,-1,0,1,0};
        for(d=0;d<4;d++) {
            int nr = dir[d],nc = dir[d+1];
            if(nr<0 || nr>=m || nc<0 || nc>=n)
               continue;

            ll cost = grid[0][0] + grid[nr][nc];
            dist[nr][nc][0][d] = cost;
            pq.push({cost,nr,nc,0,d});
        }

        if(m==1 && n==1) return grid[0][0];

        while(!pq.empty()) {
            auto [cost, r, c, turns, dr] = pq.top();
            pq.pop();

            if(cost!=dist[r][c][turns][dr])
               continue;

            for(d=0;d<4;d++) {
                int nr = r + dir[d];
                int nc = c + dir[d+1];
                if(nr<0 || nr>=m || nc<0 || nc>=n)
                   continue;

                int nturns = turns;

                if(d!=dr) nturns++;
                if(nturns>k) continue;

                ll nCost = cost+grid[nr][nc];

                if(nCost<dist[nr][nc][nturns][d]) {
                    dist[nr][nc][nturns][d] = nCost;
                    pq.push({nCost,nr,nc,nturns,d});
                }
                
            }
        }
        ll ans = INF;

        for(i=0;i<=k;i++) {
            for(j=0;j<4;j++) {
                ans = min(ans,dist[m-1][n-1][i][j]);
            }
        }
        return ans==INF?-1:(int)ans;
    }
};