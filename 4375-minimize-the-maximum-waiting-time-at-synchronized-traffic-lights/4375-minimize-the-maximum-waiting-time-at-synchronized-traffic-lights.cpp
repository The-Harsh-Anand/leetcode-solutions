class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxlight=*max_element(lights.begin(),lights.end());
        int penalty=0,i,n=arrivalTime.size(),maxpen=0;
        for(i=0;i<n;i++) {
            int r = arrivalTime[i]%period;
            penalty = 0;
            if(r>=maxlight) penalty = (period-r);
            maxpen = max(maxpen,penalty);
        }
        return maxpen;
    }
};