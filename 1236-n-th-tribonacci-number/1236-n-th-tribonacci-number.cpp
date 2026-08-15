class Solution {
public:
    int tribonacci(int n) {
        int t0=0,t1=1,t2=1,t=0;
        if(n==0) return n;
        if(n==1 || n==2) return 1;
        while(n>2) {
            t = t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=t;
            n--;
        }
        return t2;
    }
};