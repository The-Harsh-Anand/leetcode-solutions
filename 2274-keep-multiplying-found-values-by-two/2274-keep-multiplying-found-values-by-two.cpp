class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> hash(1001,0);
        int i,n=nums.size();
        for(i=0;i<n;i++) hash[nums[i]]++;
        while(original<1001 && hash[original]) original*=2;
        return original;
    }
};