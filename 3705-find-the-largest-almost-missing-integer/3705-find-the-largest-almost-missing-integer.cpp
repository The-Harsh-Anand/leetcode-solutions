class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int i,n=nums.size(),ans=-1;
        for(i=0;i<n;i++) hash[nums[i]]++;
        if(k==1) {
            for(auto it:hash) {
                if(it.second==1) ans=max(ans,it.first);
            }
            return ans;
        } else if(k==n) {
            for(auto it:hash) ans=max(ans,it.first);
            return ans;
        }
        if(hash[nums[0]]==1 && hash[nums[n-1]]==1) return max(nums[0],nums[n-1]);
        else if(hash[nums[0]]==1) return nums[0];
        else if(hash[nums[n-1]]==1) return nums[n-1];
        return -1;
    }
};