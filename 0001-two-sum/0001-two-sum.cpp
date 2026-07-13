class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Two pointers
        int i, j, n = nums.size();
        vector<pair<int, int>> hash(n);
        for (i = 0; i < n; i++) {
            hash[i].first = nums[i];
            hash[i].second = i;
        }
        sort(hash.begin(), hash.end());
        i = 0;
        j = n - 1;
        int sum = 0;
        while (i < j) {
            sum = hash[i].first + hash[j].first;
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                return {hash[i].second, hash[j].second};
            }
        }
        return {};
    }
};