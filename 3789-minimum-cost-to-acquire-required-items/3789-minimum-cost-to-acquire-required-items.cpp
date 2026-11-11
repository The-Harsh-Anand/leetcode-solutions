class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=1LL*min(costBoth,cost1+cost2)*min(need1,need2);
        ans = ans + 1LL*max(0,need1-min(need1,need2))*min(cost1,costBoth);
        ans = ans + 1LL*max(0,need2-min(need1,need2))*min(cost2,costBoth);
        return ans;
    }
};