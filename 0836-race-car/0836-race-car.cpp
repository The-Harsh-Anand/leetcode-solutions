class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target+1,-1);
        int i,m,j;
        for(i=1;i<=target;i++) {
            dp[i] = INT_MAX;
            m = 1; j = 1;
            for(;j<i;j=(1<<++m)-1) {
                for(int q=0,p=0; p<j;p=(1<<++q)-1) {
                    dp[i] = min(dp[i],m+1+q+1+dp[i-(j-p)]);
                }
            }
            dp[i] = min(dp[i],m+(i==j?0:1+dp[j-i]));
        }
        return dp[target];
    }
};