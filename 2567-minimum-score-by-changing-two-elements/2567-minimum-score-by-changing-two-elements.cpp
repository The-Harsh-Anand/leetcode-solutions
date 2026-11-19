class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        const int M=INT_MAX;
        int s0=M,s1=M,s2=M;
        int l0=0,l1=0,l2=0;
        for(int x:nums) {
            if(x<s0){
                s2=s1;
                s1=s0;
                s0=x;
            } else if(x<s1) {
                s2=s1;
                s1=x;
            } else if(x<s2) {
                s2=x;
            }

            if(x>l0){
                l2=l1;
                l1=l0;
                l0=x;
            } else if(x>l1) {
                l2=l1;
                l1=x;
            } else if(x>l2) {
                l2=x;
            }
        }
        return min({l0-s2,l2-s0,l1-s1});
    }
};