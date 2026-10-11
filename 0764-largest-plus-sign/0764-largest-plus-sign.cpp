class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> left(n+2,vector<int>(n+2,0));
        vector<vector<int>> right(n+2,vector<int>(n+2,0));
        vector<vector<int>> up(n+2,vector<int>(n+2,0));
        vector<vector<int>> down(n+2,vector<int>(n+2,0));
        vector<vector<int>> grid(n,vector<int>(n,1));
        //0->up,1->right,2->down,3->left
        int i,j;
        for(i=0;i<mines.size();i++) {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        for(i=1;i<n+1;i++) {
            for(j=1;j<n+1;j++) {
                if(grid[i-1][j-1]) left[i][j] = left[i][j-1]+1;
                if(grid[i-1][n-j]) right[i][n-j+1] = right[i][n-j+2]+1;
                if(grid[i-1][j-1]) up[i][j] = up[i-1][j]+1;
                if(grid[n-i][j-1]) down[n-i+1][j] = down[n-i+2][j]+1;
            }
        }
        
        // for(i=0;i<n+2;i++) {
        //     for(j=0;j<n+2;j++) {
        //         cout<<up[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n\n";
        // for(i=0;i<n+2;i++) {
        //     for(j=0;j<n+2;j++) {
        //         cout<<right[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n\n";
        // for(i=0;i<n+2;i++) {
        //     for(j=0;j<n+2;j++) {
        //         cout<<down[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n\n";
        // for(i=0;i<n+2;i++) {
        //     for(j=0;j<n+2;j++) {
        //         cout<<left[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n\n";
        int ans=0;
        for(i=1;i<n+1;i++) {
            for(j=1;j<n+1;j++) {
                if(grid[i-1][j-1])
                ans=max(ans,min({up[i][j],down[i][j],right[i][j],left[i][j]}));
            }
        }
        return ans;
    }
};