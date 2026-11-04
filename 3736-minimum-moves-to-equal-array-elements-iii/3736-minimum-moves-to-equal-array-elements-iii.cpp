class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size(),i,ctr=0;
        int maxn=*max_element(nums.begin(),nums.end());
        for(i=0;i<n;i++) ctr+=(maxn-nums[i]);
        return ctr;
    }
};