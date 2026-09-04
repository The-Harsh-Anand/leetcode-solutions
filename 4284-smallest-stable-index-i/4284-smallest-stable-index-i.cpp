class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),i;
        vector<int> pre(n),post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(i=1;i<n;i++) {
            pre[i] = max(nums[i],pre[i-1]);
            post[n-1-i] = min(nums[n-1-i],post[n-i]);
        }
        int ind=INT_MAX;
        for(i=0;i<n;i++) {
            if(pre[i]-post[i]<=k)
                ind = min(i,ind);
        }
        if(ind==INT_MAX) return -1;
        return ind;
    }
};