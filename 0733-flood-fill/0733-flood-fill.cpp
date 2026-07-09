class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int scol) {
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=scol)
            return;
        
        image[r][c] = color;

        dfs(image, r-1, c, color,scol);
        dfs(image, r+1, c, color,scol);
        dfs(image, r, c-1, color,scol);
        dfs(image, r, c+1, color,scol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int scol = image[sr][sc];
        if(scol!=color) dfs(image,sr,sc,color,scol);
        return image;
    }
};