class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0, n= nums.size(),flag=0;
        for(auto i:nums) {
            if(i!=0) flag=1;
            total^=i;
        }
        if(total!=0) return n;
        return flag?n-1:0;
    }
};