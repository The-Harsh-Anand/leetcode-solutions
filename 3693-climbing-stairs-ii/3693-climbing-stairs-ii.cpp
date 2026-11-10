class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int i;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=costs[0]+1;
        if(n==1) return dp[n];
        dp[2]=min(dp[1]+costs[1]+1,dp[0]+costs[1]+4);
        for(i=3;i<=n;i++) {
            int c1 = dp[i-3]+costs[i-1]+9;
            int c2 = dp[i-2]+costs[i-1]+4;
            int c3 = dp[i-1]+costs[i-1]+1;
            dp[i]=min({c1,c2,c3});
        }
        return dp[n];
    }
};