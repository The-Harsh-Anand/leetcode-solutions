class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999) return 0;

        long long ans=0,ctr=1,prev=1000, next=prev*1000-1;
        while(prev<=n) {
            ans += 1LL*ctr*(min(n,next)-prev+1);
            if(next>n) break;
            prev = prev*1000;
            next = prev*1000-1;
            ctr++;
        }
        return ans;
    }
};