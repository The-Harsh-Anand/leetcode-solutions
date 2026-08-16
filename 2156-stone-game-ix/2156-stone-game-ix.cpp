class Solution {
public:
    // void printqueue(queue<int> q) {
    //     while(!q.empty()) {
    //         cout<<q.front()<<" ";
    //         q.pop();
    //     }
    //     cout<<"\n";
    // }
    bool stoneGameIX(vector<int>& stones) {
        // int remsum = 0, i, n = stones.size();
        // bool turn = true;
        // int notpicked = 0;
        // queue<int> q;
        // for(i=0;i<n;i++) {
        //     cout<<stones[i]<<" ";
        //     q.push(stones[i]);
        // }
        // cout<<"\n";
        // while (!q.empty() && (remsum % 3 != 0 || remsum == 0) && notpicked!=q.size()) {
        //     if ((remsum + q.front()) % 3 != 0) {
        //         remsum += q.front();
        //         q.pop();
        //         cout<<turn<<" op1 ";
        //         // printqueue(q);
        //         notpicked=0;
        //         turn = !turn;
        //     } else {
        //         q.push(q.front());
        //         notpicked++;
        //         q.pop();
        //         cout<<turn<<" op2 ";
        //         // printqueue(q);
        //     }
        // }
        // if(!q.empty()) {
        //     return !turn;
        // } else if(turn) return remsum%3!=0;
        // return false;

        vector<int> cnt(3,0);
        for(auto i:stones) cnt[i%3]++;
        if(cnt[0]%2==0) return cnt[1]>0 && cnt[2]>0;
        return abs(cnt[1]-cnt[2])>2;
    }
};