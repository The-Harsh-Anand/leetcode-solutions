class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<vector<int>> q;
        int i,j,m=board.size(),n=board[0].size();
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(board[i][j]=='O' && (i==0||j==0||i==m-1||j==n-1)) {
                    q.push({i,j});
                    board[i][j]='B';
                }
            }
        }
        //MULTISOURCE BFS
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();
            for(i=0;i<4;i++) {
                int r = abs(row+dir[i][0]);
                int c = abs(col+dir[i][1]);
                if(r<m && c<n && board[r][c]=='O') {
                    board[r][c] = 'B';
                    q.push({r,c});
                } 
            }
        }

        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='B') board[i][j]='O';
            }
        }
    }
};