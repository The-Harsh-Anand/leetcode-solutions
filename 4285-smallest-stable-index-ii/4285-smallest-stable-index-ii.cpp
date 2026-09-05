class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),i;
        vector<int> post(n);
        int pre = nums[0];
        post[n-1] = nums[n-1];
        for(i=n-2;i>=0;i--)   post[i] = min(nums[i],post[i+1]);
        int ind=INT_MAX;
        for(i=0;i<n;i++) {
            pre = max(pre,nums[i]);
            if(pre-post[i]<=k)
                ind = min(i,ind);
        }
        if(ind==INT_MAX) return -1;
        return ind;
    }
};