class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> path(m,"");
        int i,j;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(j==0 || i==m-1) path[i]+=".";
                else path[i]+="#";
            }
        }
        return path;
    }
};