class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startval=1,sum=0,i,n=nums.size();
        for(i=0;i<n;i++) {
            sum+=nums[i];
            if(sum<1) {
                startval=max(startval,1-sum);
            }
        }
        return startval;
    }
};