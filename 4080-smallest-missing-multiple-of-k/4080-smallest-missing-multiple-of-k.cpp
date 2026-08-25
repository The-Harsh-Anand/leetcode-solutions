class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i,n=nums.size();
        vector<bool> hash(101,false);
        for(i=0;i<n;i++)  hash[nums[i]]=true;
        for(i=k;i<=100 && hash[i];i+=k);
        return i;
    }
};