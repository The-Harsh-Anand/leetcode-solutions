class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        int i=0,j;
        vector<vector<int>> mat(grid.begin(),grid.end());
        vector<int> row(n,0), col(n,0);
        for(i=0;i<n;i++) {
            int k = rowShift[i];
            for(j=0;j<n;j++) {
                row[(j-k+n)%n] = mat[i][j];
            }
            mat[i] = row;
        }
        for(i=0;i<n;i++) {
            int k = colShift[i];
            for(j=0;j<n;j++) {
                col[(j-k+n)%n] = mat[j][i];
            }
            for(j=0;j<n;j++) {
                mat[j][i] = col[j];
            }
        }
        return mat;
    }
};