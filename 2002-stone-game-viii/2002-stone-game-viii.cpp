class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size(),i;
        vector<int> prefix(n,0);
        prefix[0] = stones[0];
        for(i=1;i<n;i++) prefix[i] = prefix[i-1]+stones[i];
        int ans = prefix[n-1];
        for(i=n-2;i>=1;i--) {
            ans = max(ans,prefix[i]-ans);
        }
        return ans;
    }
};