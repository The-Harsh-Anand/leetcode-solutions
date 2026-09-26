class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int i,j,n=target.size();
        long long sum1=0,sum2=0;
        for(i=0;i<n;i++) {
            sum1+=source[i];
            sum2+=target[i];
        }
        return sum1==sum2;
    }
};