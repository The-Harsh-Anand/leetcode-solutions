class Solution {
public:
    int rob(vector<int>& nums, int start, int end) {
        int i;
        int x = 0, y = 0,z=y;
        for(i=start;i<end;i++) {
            z = max(x+nums[i],y);
            x=y;
            y=z;
        }
        return z;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(rob(nums,0,n-1),rob(nums,1,n));
    }
};