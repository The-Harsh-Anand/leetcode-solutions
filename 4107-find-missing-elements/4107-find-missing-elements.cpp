class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=101,mx=0,i,n=nums.size();
        vector<bool> has(101,false);
        for(i=0;i<n;i++) {
            has[nums[i]] = true;
            mn = min(nums[i],mn);
            mx = max(nums[i],mx);
        }
        vector<int> ans;
        for(i=mn;i<=mx;i++) {
            if(!has[i]) ans.push_back(i);
        }
        return ans;
    }
};