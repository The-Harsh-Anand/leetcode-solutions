class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),i,j;
        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(i==0 && j==0) {
                    dp[i][j].insert(grid[i][j]);
                } else if(i==0) {
                    dp[i][j].insert(*dp[i][j-1].begin()^grid[i][j]);
                } else if(j==0) {
                    dp[i][j].insert(*dp[i-1][j].begin()^grid[i][j]);
                } else {
                    for(auto& it:dp[i-1][j])
                        dp[i][j].insert(it^grid[i][j]);
                    for(auto& it:dp[i][j-1])
                        dp[i][j].insert(it^grid[i][j]);
                }
            }
        }
        int ans=INT_MAX;
        for(auto& it:dp[m-1][n-1]) ans=min(ans,it);
        return ans;
        
    }
};