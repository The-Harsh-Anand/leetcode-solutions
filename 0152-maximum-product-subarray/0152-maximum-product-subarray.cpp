class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0,currprod=1,maxprod=INT_MIN;
        while(r<n) {
            while(r<n && nums[r]!=0) {
                currprod*=nums[r];
                maxprod = max(maxprod,currprod);
                r++;
            }
            while(l<r-1 && nums[l]!=0) {
                currprod/=nums[l];
                maxprod = max(maxprod,currprod);
                l++;
            }
            if(r<n && nums[r]==0) {
                maxprod = max(maxprod,0);
                currprod=1;
                r++;
                l=r;
            }
        }
        return maxprod;
    }
};