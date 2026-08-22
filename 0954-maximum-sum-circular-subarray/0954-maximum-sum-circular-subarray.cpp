class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=INT_MIN/10,flag=0,csum1=0,csum2=0,minsum=INT_MAX/10,i,total=0,n=nums.size();
        for(i=0;i<n;i++) {
            csum1+=nums[i];
            csum2+=nums[i];
            total+=nums[i];
            if(nums[i]>0) flag=1;
            maxsum = max(maxsum,csum1);
            minsum = min(minsum,csum2);
            if(csum1<0) csum1=0;
            if(csum2>0) csum2=0;
        }
        if(!flag) return maxsum;
        return max(maxsum,total-minsum);
    }
};