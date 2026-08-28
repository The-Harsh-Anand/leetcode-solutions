class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> ans(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--)
            for(int j=0;j<i;j++) 
                ans[j] = (ans[j]+ans[j+1])%10;
        return ans[0];
    }
};