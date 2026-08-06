class Solution {
public:
    int prod(int x) {
        if(x<=9) return x;
        return x%10*prod(x/10);
    }
    int smallestNumber(int n, int t) {
        int x=n;
        while(prod(x++)%t);
        return x-1;
    }
};