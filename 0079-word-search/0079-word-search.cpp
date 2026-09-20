class Solution {
public:
    vector<int> dir={0,-1,0,1,0};
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& isVisited, string& word, int ind, int x, int y) {
        int m=isVisited.size(),n=isVisited[0].size(),k=word.length(),i;
        if(ind==k) return true;
        isVisited[x][y]=true;
        for(i=0;i<4;i++) {
            int r = x+dir[i];
            int c = y+dir[i+1];
            if(r>=0 && r<m && c>=0 && c<n && !isVisited[r][c] && board[r][c]==word[ind]) {
                if(dfs(board,isVisited,word,ind+1,r,c)) return true;
            }
        }
        isVisited[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int i,j,m=board.size(),n=board[0].size();
        vector<vector<bool>> isVisited(m,vector<bool>(n,false));
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(board[i][j]==word[0]) {
                    if(dfs(board,isVisited,word,1,i,j)) return true;
                }
            }
        }
        return false;
    }
};