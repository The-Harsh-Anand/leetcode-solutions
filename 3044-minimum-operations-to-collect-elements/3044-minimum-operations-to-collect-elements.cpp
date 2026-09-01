class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size(),i,j,flag=0;
        vector<int> hash(k+1,0);
        for(i=n-1;i>=0;i--) {
            if(nums[i]>k) continue;
            hash[nums[i]]=1;
            flag=1;
            for(j=1;j<=k;j++) {
                if(hash[j]==0) flag=0;
            }
            if(flag==1) break;
        }
        return n-i;
    }
};