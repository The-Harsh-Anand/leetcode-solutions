class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(), ans=0, i;
        sort(nums.begin(),nums.end());
        int mid = n%2?nums[n/2]:(nums[n/2]+nums[n/2-1])/2;
        cout<<mid;
        for(i=0;i<n;i++){
            if(nums[i]!=mid) {
                ans+=abs(nums[i]-mid);
            }
        }
        return ans;
    }
};