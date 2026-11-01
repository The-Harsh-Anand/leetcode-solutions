class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i,n=nums.size();
        int minel=INT_MAX,sum=0;
        for(i=0;i<n;i++) {
            minel=min(minel,nums[i]);
            sum+=nums[i];
        }
        int ans = sum-minel*n;
        return ans;
    }
};