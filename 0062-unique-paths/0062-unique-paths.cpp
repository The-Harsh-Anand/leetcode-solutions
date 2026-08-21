class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans=1, j=1;
        for(int i=m+n-2;i>=max(m,n);i--)  ans=(ans*i)/j++;
        return ans;
    }
};