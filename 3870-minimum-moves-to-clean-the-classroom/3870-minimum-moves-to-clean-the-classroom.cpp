class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();

        int total=0,sr=0,sc=0,i,j;
        vector<vector<int>> id(m,vector<int>(n,-1));

        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(classroom[i][j]=='S') {
                    sr=i;sc=j;
                } else if(classroom[i][j]=='L') {
                    id[i][j] = total++;
                }
            }
        }

        int mask = 1<<total; //all the litters represented in bits
        int fullMask = mask-1;

        vector<vector<vector<int>>> bestEng(m,vector<vector<int>>(n,vector<int>(mask,-1)));
        vector<int> dir = {0,-1,0,1,0};
        queue<vector<int>> q;
        q.push({sr,sc,0,energy,0}); 
        //q{start_row, start_col, collected_litter, curr_energy, steps}

        while(!q.empty()) {
            vector<int> state = q.front();
            q.pop();

            if(state[2]==fullMask) return state[4];
            if(state[3]==0) continue;

            for(i=0;i<4;i++) {
                int nr = abs(state[0]+dir[i]);
                int nc = abs(state[1]+dir[i+1]);

                if(nr>=m || nc>=n || classroom[nr][nc]=='X') continue;

                int neng = state[3]-1;
                int nMask = state[2];

                char cell = classroom[nr][nc];
                if(cell=='L')   nMask = nMask|(1<<id[nr][nc]);
                else if(cell=='R')   neng = energy;

                if(bestEng[nr][nc][nMask]>=neng) continue;

                bestEng[nr][nc][nMask] = neng;
                q.push({nr,nc,nMask,neng,state[4]+1});
            }
        }
        return -1;
    }
};