class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int i;
        int dp0=0;
        int dp1=costs[0]+1;
        if(n==1) return dp1;
        int dp2=min(dp1+costs[1]+1,dp0+costs[1]+4);
        for(i=3;i<=n;i++) {
            int c1 = dp0+9;
            int c2 = dp1+4;
            int c3 = dp2+1;
            dp2=costs[i-1]+min({c1,c2,c3});
            dp1=c3-1;
            dp0=c2-4;
        }
        return dp2;
    }
};