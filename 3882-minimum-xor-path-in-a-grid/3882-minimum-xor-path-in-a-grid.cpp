class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),i,j,k;
        vector<vector<vector<bool>>> dp(m,vector<vector<bool>>(n,vector<bool>(1024,false)));
        dp[0][0][grid[0][0]]=true;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                for(k=0;k<1024;k++) {
                    if(!dp[i][j][k]) continue;
                    if(i+1<m) {
                        dp[i+1][j][grid[i+1][j]^k]=true;
                    }
                    if(j+1<n) {
                        dp[i][j+1][grid[i][j+1]^k]=true;
                    }
                }
            }
        }

        for(k=0;k<1024;k++) if(dp[m-1][n-1][k]) break;
        return k;
        
    }
};