class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int i,n=intervals.size(),ctr=0,j;
        for(i=0;i<n;i++) {
            int x=intervals[i][0],y=intervals[i][1];
            for(j=i+1;j<n;j++) {
                int p=intervals[j][0],q=intervals[j][1];
                if((x<=p && p<=y)||(p<=x && x<=q)) ctr++;
            }
        }
        return ctr;
    }
};