class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9,vector<int>(9,0));
        vector<vector<int>> cols(9,vector<int>(9,0));
        vector<vector<int>> box(9,vector<int>(9,0));
        int i,j;
        for(i=0;i<9;i++) {
            for(j=0;j<9;j++) {
                if(board[i][j]=='.') continue;
                int n = board[i][j]-'1';
                rows[i][n]++;
                cols[j][n]++;
                box[i/3*3+j/3][n]++;
                if(rows[i][n]>1 || cols[j][n]>1 || box[i/3*3+j/3][n]>1) return false;
            }
        }
        return true;
    }
};