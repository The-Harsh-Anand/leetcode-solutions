class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rS) {
        int i,j,sz=rS.size();
        unordered_map<int,short> seat;
        for(auto& r:rS) {
            if(r[1]==1||r[1]==10) continue;
            if(r[1]>=2 && r[1]<=5) seat[r[0]] = seat[r[0]] | (1<<2);
            if(r[1]>=4 && r[1]<=7) seat[r[0]] = seat[r[0]] | (1<<1);
            if(r[1]>=6 && r[1]<=9) seat[r[0]] = seat[r[0]] | (1<<0);
        }
        int count=(n-seat.size())*2;
        for(auto& it:seat) {
            bool b1 = it.second & (1<<2);
            bool b2 = it.second & (1<<1);
            bool b3 = it.second & (1<<0);
            if(!b1&&!b3) count+=2;
            else if(!b1||!b2||!b3) count+=1;
        }
        return count;
    }
};