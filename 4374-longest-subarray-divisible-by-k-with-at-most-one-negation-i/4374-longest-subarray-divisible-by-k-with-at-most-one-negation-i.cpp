class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),i,j,t,maxl=0;
        vector<int> arr(k,-1);
        for(i=0;i<n;i++) {
            long long sum=0;
            for(j=i;j<n;j++) {
                sum+=nums[j];
                arr[(((2*nums[j])%k)+k)%k] = i;
                if(((sum%k)+k)%k==0||arr[((sum%k)+k)%k]==i)
                    maxl=max(maxl,j-i+1);
            }
        }
        return maxl;
    }
};