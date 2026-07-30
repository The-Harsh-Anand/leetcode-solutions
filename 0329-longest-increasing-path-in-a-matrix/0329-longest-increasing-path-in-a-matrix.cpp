class Solution {
private:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>&len, int row, int col) {
        int m=matrix.size(),n=matrix[0].size(),i;
        int parent = matrix[row][col];
        int temp = 0;
        for(i=0;i<4;i++) {
            int r = abs(row+dir[i][0]);
            int c = abs(col+dir[i][1]);

            if(r<m && c<n && matrix[r][c]>parent) {
                if(len[r][c]!=-1) temp = max(len[r][c],temp);
                else {
                    len[r][c] = dfs(matrix,len,r,c);
                    temp = max(temp, len[r][c]);
                }
            }
        }
        return 1+temp;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> len(m,vector<int>(n,-1));
        int i,j,ans=1;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(len[i][j]==-1) {
                    len[i][j]=dfs(matrix,len,i,j);
                }
                ans = max(ans,len[i][j]);
            }
        }
        return ans;
    }
};