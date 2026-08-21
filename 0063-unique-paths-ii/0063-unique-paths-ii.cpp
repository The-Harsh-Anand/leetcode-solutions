class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size(), n=obstacleGrid[0].size(),i,j;
        vector<int> dp(n,0);
        dp[0]=1;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(obstacleGrid[i][j]==1) dp[j]=0;
                else if(j>0) dp[j]= (dp[j-1]+dp[j]);
            }
        }
        return dp[n-1];
    }
};