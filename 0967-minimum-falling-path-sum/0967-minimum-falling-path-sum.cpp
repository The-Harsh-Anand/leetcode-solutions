class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i, j, n = matrix.size(), ans = INT_MAX;
        if (n == 1)
            return matrix[0][0];
        vector<int> dp(matrix[0].begin(), matrix[0].end());
        int left = INT_MAX, right = INT_MAX, center = INT_MAX;
        for (i = 1; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j == 0) {
                    left = INT_MAX;
                    center = dp[j];
                    right = dp[j + 1];
                }
                dp[j] = min({left, center, right}) + matrix[i][j];
                left = center;
                center = right;
                if (j < n - 2)
                    right = dp[j + 2];
                else
                    right = INT_MAX;
                if (i == n - 1)
                    ans = min(ans, dp[j]);
            }
        }
        return ans;
    }
};