class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size(),i,j,k,minsum=INT_MAX,ctr=0;
        for(i=0;i<n;i++) {
            for(j=i+l-1;j<=min(n-1,i+r-1);j++) {
                int currsum=0;
                for(k=i;k<=j;k++) {
                    currsum+=nums[k];
                }
                if(currsum>0) minsum=min(minsum,currsum);
            }
            if(l==1 && r==1 && nums[i]>0) {
                minsum=min(minsum,nums[i]);
            }
        }
        return minsum==INT_MAX?-1:minsum;
    }
};