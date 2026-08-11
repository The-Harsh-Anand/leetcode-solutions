class Solution {
public:
    int rob(vector<int>& nums) {
        int i,n=nums.size();
        if(n==0) return 0;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(i=1;i<n;i++) {
            dp[i+1] = max(dp[i-1]+nums[i],dp[i]);
        }
        return dp[n];
    }
};