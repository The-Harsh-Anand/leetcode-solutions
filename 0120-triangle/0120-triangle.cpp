class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),i,j,sum=0,prev=INT_MIN,temp;
        vector<int> dp(n,INT_MIN);
        dp[0] = triangle[0][0];
        for(i=1;i<n;i++) {
            for(j=0;j<=i;j++) {
                if(prev==INT_MIN) {
                    prev = dp[j];
                    dp[j]=dp[j]+triangle[i][j];
                } else if(j==i){
                    dp[j]=prev+triangle[i][j];
                    prev = INT_MIN;
                } else {
                    temp = dp[j];
                    dp[j] = min(dp[j],prev)+triangle[i][j];
                    prev = temp;
                }
            }
        }
        return *min_element(dp.begin(),dp.end());

    }
};