class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i;
        set<int> hash(nums.begin(),nums.end());
        for(i=k;hash.contains(i);i+=k);
        return i;
    }
};