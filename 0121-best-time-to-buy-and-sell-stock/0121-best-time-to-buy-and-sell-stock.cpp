class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=INT_MIN,i,j,n=prices.size(),profit=0;
        for(i=1;i<n;i++) {
            if(buy>prices[i]) {
                buy=prices[i];
            }
            profit = max(profit,prices[i]-buy);
        }
        return profit;
    }
};