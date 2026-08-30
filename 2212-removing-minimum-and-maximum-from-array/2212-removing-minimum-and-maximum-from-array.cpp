class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mnidx=0,mxidx=0,mn=INT_MAX,mx=INT_MIN;
        int i,n=nums.size();
        for(i=0;i<n;i++) {
            if(nums[i]<mn) {
                mn = nums[i];
                mnidx=i;
            }
            if(nums[i]>mx) {
                mx = nums[i];
                mxidx = i;
            }
        }
        mn = min(mnidx,mxidx);
        mx = max(mnidx,mxidx);
        int c1 = mn+(n-mx)+1;
        int c2 = mx+1;
        int c3 = n-mn;
        return min({c1,c2,c3});
    }
};