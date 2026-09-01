class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k==1) return 0;
        long long currprod=0,ctr=0;
        int l=0,r=0,n=nums.size();
        while(l<=r && r<n) {
            currprod+=nums[r];
            while(l<n && currprod*(r-l+1)>=k) {
                currprod-=nums[l];
                l++;
            }
            ctr+=(r-l+1);
            r++;
        }
        return ctr;
    }
};