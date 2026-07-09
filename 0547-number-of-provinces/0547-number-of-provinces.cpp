class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& isVisited, int x,int n) {
        isVisited[x] = 1;
        for(int j=0;j<n;j++) {
            if(x==j) continue;
            if(isConnected[x][j]==1 && !isVisited[j])
                dfs(isConnected, isVisited,j,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> isVisited(n,0);
        int cnt=0,i;
        for(i=0;i<n;i++) {
            if(!isVisited[i]) {
                cnt++;
                dfs(isConnected, isVisited,i,n);
            }
        }
        return cnt;
    }
};