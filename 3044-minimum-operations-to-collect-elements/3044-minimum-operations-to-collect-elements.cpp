class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size(),i,j,flag=0;
        unordered_set<int> st;
        for(i=n-1;i>=0;i--) {
            if(nums[i]<=k) st.insert(nums[i]);
            if(st.size()==k) break;
        }
        return n-i;
    }
};