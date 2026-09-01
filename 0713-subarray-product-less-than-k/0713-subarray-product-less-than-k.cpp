class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        long long currprod=1;
        int l=0,r=0,n=nums.size(),ctr=0;
        while(l<=r && r<n) {
            currprod*=nums[r];
            while(l<n && currprod>=k) {
                currprod/=nums[l];
                l++;
            }
            ctr+=(r-l+1);
            r++;
        }
        return ctr;
    }
};