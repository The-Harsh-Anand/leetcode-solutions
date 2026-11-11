class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minneed = min(need1,need2);
        long long ans=1LL*min(costBoth,cost1+cost2)*minneed;
        ans = ans + 1LL*max(0LL,need1-minneed)*min(cost1,costBoth);
        ans = ans + 1LL*max(0LL,need2-minneed)*min(cost2,costBoth);
        return ans;
    }
};