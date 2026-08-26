class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = {1};
        int ctr=1,i=0,j=0,k=0,mn;
        while(ctr<n) {
            mn = min({dp[i]*2,dp[j]*3,dp[k]*5});
            dp.push_back(mn);
            if(mn==dp[i]*2) i++;
            if(mn==dp[j]*3) j++;
            if(mn==dp[k]*5) k++;
            ctr++;
        }
        return dp[ctr-1];
    }
};