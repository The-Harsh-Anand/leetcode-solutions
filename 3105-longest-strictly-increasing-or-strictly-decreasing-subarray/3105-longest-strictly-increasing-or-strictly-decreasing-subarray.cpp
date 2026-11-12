class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int i,ctr=0,ans=1,flag=-1;
        for(i=0;i<n-1;i++) {
            if(nums[i]<nums[i+1]) {
                if(flag==0) {
                    ctr++;
                } else {
                    flag=0;
                    ctr=2;
                }
            } else if(nums[i]>nums[i+1]) {
                if(flag==1) {
                    ctr++;
                } else {
                    flag=1;
                    ctr=2;
                }
            } else {
                flag=-1;
                ctr=1;
            }
            ans=max(ans,ctr);
        }

        return ans;
    }
};