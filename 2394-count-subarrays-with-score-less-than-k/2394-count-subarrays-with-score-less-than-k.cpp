class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k==1) return 0;
        long long sum=0,ctr=0;
        int l=0,r=0,n=nums.size();
        while(l<n && r<n) {
            sum+=nums[r];
            while(sum*(r-l+1)>=k) {
                sum-=nums[l];
                l++;
            }
            ctr+=(r-l+1);
            r++;
        }
        return ctr;
    }
};