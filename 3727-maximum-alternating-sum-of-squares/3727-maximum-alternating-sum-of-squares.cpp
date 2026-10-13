class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size(),i;
        for(i=0;i<n;i++) nums[i]=(nums[i]*nums[i]);
        sort(nums.rbegin(),nums.rend());
        int x=n-n/2;
        long long ans=0;
        for(i=0;i<n;i++) {
            if(i<x) ans+=nums[i];
            else ans-=nums[i];
        }
        return ans;
    }
};