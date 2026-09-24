class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size(),i;
        for(i=0;i<n;i++) {
            if(nums[i]<10) {
                if(nums[i]==i) return i;
            } else if(nums[i]<100) {
                if(nums[i]/10+nums[i]%10==i) return i;
            } else if(nums[i]<1000){
                if(nums[i]/100+(nums[i]/10)%10+nums[i]%10==i) return i;
            } else if(i==1) return i;
        }
        return -1;
    }
};