class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int i,n=nums.size(),x;
        vector<int> v;
        long long sum=0;
        for(i=0;i<n;i++) {
            string s = to_string(nums[i]);
            sort(s.rbegin(),s.rend());
            x = stoi(s);
            sum+=nums[i];
            if(x>nums[i]) {
                v.push_back(x-nums[i]);
            }
        }
        sort(v.rbegin(),v.rend());
        for(i=0;i<min(k,(int)v.size());i++) sum+=v[i];
        return sum;
    }
};