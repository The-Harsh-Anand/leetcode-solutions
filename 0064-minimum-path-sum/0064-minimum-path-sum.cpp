class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),i,j;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = grid[0][0];
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(i==0 && j==0) continue;
                int up=INT_MAX,left=INT_MAX;
                if(i-1>=0) up = dp[i-1][j];
                if(j-1>=0) left = dp[i][j-1];
                dp[i][j] = min(up,left) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};