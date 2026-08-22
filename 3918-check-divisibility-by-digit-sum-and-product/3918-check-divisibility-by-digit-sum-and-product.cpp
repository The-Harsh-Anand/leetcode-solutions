class Solution {
public:
    bool checkDivisibility(int n) {
        int i=n,sod=0,pod=1;
        while(i!=0) {
            sod+=(i%10);
            pod*=(i%10);
            i/=10;
        }
        return n%(sod+pod)==0;
    }
};