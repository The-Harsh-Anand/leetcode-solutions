class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> attack;
        set<vector<int>> st(queens.begin(),queens.end());
        int r,c;
        //dir-1 (North)
        for(r=king[0],c=king[1];r>=0;r--) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-2 (North-East)
        for(r=king[0],c=king[1];r>=0 && c<8;r--,c++) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-3 (East)
        for(r=king[0],c=king[1];c<8;c++) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-4 (South-East)
        for(r=king[0],c=king[1];r<8&&c<8;r++,c++) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-5 (South)
        for(r=king[0],c=king[1];r<8;r++) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-6 (South-West)
        for(r=king[0],c=king[1];r<8&&c>=0;r++,c--) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-7 (West)
        for(r=king[0],c=king[1];c>=0;c--) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        //dir-8 (North-West)
        for(r=king[0],c=king[1];r>=0,c>=0;r--,c--) {
            if(st.contains({r,c})) {
                attack.push_back({r,c});
                break;
            }
        }
        return attack;
    }
};