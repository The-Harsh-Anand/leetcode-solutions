class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size(),i;
        int comb=-1;
        for(i=0;i<n;i++) {
            if(nums[i]!=i) {
                if(comb==-1) comb=nums[i];
                else comb=comb&nums[i];
            }
        }
        return comb==-1?0:comb;
    }
};