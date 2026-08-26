class Solution {
public:
    bool isUgly(int n) {
        if(n==0) return false;
        int t=n;
        while(t%2==0) t/=2;
        while(t%3==0) t/=3;
        while(t%5==0) t/=5;
        return t==1;
    }
};