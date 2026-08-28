class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,0);
        ans[0]=1;
        int i,j;
        for(i=1;i<=rowIndex+1;i++) {
            int t1 = ans[0],t2 = ans[1];
            for(j=1;j<i;j++) {
                ans[j] = t1+t2;
                t1 = t2;
                if(j+1<rowIndex) t2 = ans[j+1];
                else t2=0;
            }
        }
        return ans;
    }
};