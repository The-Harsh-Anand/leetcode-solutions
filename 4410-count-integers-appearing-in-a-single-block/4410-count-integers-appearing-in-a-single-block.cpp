class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        set<int> hash,ans;
        int i=0,n=nums.size();
        for(i=0;i<n;i++) {
            if(i==0 || nums[i]!=nums[i-1]) {
                if(hash.contains(nums[i])) ans.erase(nums[i]);
                else {
                    ans.insert(nums[i]);
                    hash.insert(nums[i]);
                }
            }
        }
        return ans.size();
    }
};