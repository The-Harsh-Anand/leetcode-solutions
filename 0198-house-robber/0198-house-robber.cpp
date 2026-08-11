class Solution {
public:
    int rob(vector<int>& nums) {
        int i,n=nums.size();
        if(n==0) return 0;
        int x = 0, y = nums[0],z=y;
        for(i=1;i<n;i++) {
            z = max(x+nums[i],y);
            x=y;
            y=z;
        }
        return z;
    }
};