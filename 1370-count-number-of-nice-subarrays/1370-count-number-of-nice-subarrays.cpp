class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(), odd_counter=0,counter=0;
        if(k==-1) return 0;
        while(r<n) {
            if(nums[r]%2) odd_counter++;
            while(odd_counter>k) {
                if(nums[l]%2) odd_counter--;
                l++;
            }
            counter+=(r-l+1);
            r++;
        }
        return counter;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};