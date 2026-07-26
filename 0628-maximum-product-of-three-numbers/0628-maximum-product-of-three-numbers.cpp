class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size(),i,l=0,r=n-1;
        sort(nums.begin(),nums.end());
        int p1 = nums[n-1]*nums[n-2]*nums[n-3];
        int p2 = nums[0]*nums[1]*nums[2];
        int p3 = nums[0]*nums[1]*nums[n-1];
        int p4 = nums[0]*nums[n-1]*nums[n-2];
        int maxprod = max({p1,p2,p3,p4});
        return maxprod;
    }
};