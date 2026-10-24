class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<vector<int>> al(2,vector<int>(2,0)), bob(2,vector<int>(2,0));
        //0 => Arrive, 1 => Leave
        al[0][0] = stoi(arriveAlice.substr(3));
        al[0][1] = stoi(arriveAlice.substr(0,2));
        al[1][0] = stoi(leaveAlice.substr(3));
        al[1][1] = stoi(leaveAlice.substr(0,2));
        bob[0][0] = stoi(arriveBob.substr(3));
        bob[0][1] = stoi(arriveBob.substr(0,2));
        bob[1][0] = stoi(leaveBob.substr(3));
        bob[1][1] = stoi(leaveBob.substr(0,2));
        int minleave = min(f(al[1][1],al[1][0]),f(bob[1][1],bob[1][0]));
        int maxarrive = max(f(al[0][1],al[0][0]),f(bob[0][1],bob[0][0]));
        int ans = max(0,minleave-maxarrive+1);
        return ans;
    }
    int f(int m, int q) {
        return (275*m)/9-30-2*((m+9)/12)+q;
    }
};