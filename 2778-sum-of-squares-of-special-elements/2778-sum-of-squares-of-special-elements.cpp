class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sos=0,i,n=nums.size();
        for(i=0;i<n;i++) {
            if(n%(i+1)==0) sos+=nums[i]*nums[i];
        }
        return sos;
    }
};