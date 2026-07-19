class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& board, int row, int col) {
        board[row][col]='B';
        int i,m=board.size(),n=board[0].size();
        for(i=0;i<4;i++) {
            int r = abs(row+dir[i][0]);
            int c = abs(col+dir[i][1]);
            if(r<m && c<n && board[r][c]=='O')
                dfs(board,r,c);
        }
    }
    void solve(vector<vector<char>>& board) {
        queue<vector<int>> q;
        int i,j,m=board.size(),n=board[0].size();
        for(j=0;j<n;j++) {
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[m-1][j]=='O') dfs(board,m-1,j);
        }
        for(j=0;j<m;j++) {
            if(board[j][0]=='O') dfs(board,j,0);
            if(board[j][n-1]=='O') dfs(board,j,n-1);
        }
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='B') board[i][j]='O';
            }
        }
    }
};