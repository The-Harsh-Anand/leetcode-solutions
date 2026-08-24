class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i, j, n = matrix.size(), ans = INT_MAX,k;
        if (n == 1)
            return matrix[0][0];
        vector<int> dp(matrix[0].begin(), matrix[0].end());
        vector<int> temp(n,INT_MIN);
        for (i = 1; i < n; i++) {
            temp = dp;
            for (j = 0; j < n; j++) {
                int mn = INT_MAX;
                for(k=0;k<n;k++) {
                    if(k==j) continue;
                    mn = min(temp[k],mn);
                }
                dp[j] = mn+matrix[i][j];
                if(i==n-1) ans = min(ans,dp[j]);
            }
        }
        return ans;
    }
};