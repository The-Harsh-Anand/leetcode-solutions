class Solution {
public:
    int maxProduct(int n) {
        vector<int> digs;
        int t=n;
        while(t!=0) {
            digs.push_back(t%10);
            t/=10;
        }
        int ans=0,i,j;
        for(i=0;i<digs.size();i++) {
            for(j=i+1;j<digs.size();j++) {
                ans = max(ans,digs[i]*digs[j]);
            }
        }
        return ans;
    }
};