typedef unsigned long long ull;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length(),n=t.length(),i,j;
        vector<ull> dp(n+1,0);
        dp[n]=1;
        for(i=m-1;i>=0;i--) {
            for(j=0;j<n;j++) {
                if(s[i]==t[j]) dp[j] = dp[j+1]+dp[j];
            }
        }
        return dp[0];
    }
};