class Solution {
public:
    int getNext(int i, vector<int>& nums, bool isFwd) {
        int n=nums.size();
        if((nums[i]>0)!=isFwd) return -1;
        int nextidx=((i+nums[i])%n+n)%n;
        if(nextidx==i) return -1;
        return nextidx;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size(),i;
        for(i=0;i<n;i++) {
            if(nums[i]==0) continue;
            int slow=i,fast=i;
            bool isFwd=nums[i]>0;
            while(true) {
                slow=getNext(slow,nums,isFwd);
                fast=getNext(fast,nums,isFwd);
                if(fast!=-1) {
                    fast=getNext(fast,nums,isFwd);
                }
                if(slow==-1||fast==-1) break;
                if(slow==fast) return true;
            }
        }
        return false;
    }
};