class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int p1=0,p2=0,n=series1.size(),m=series2.size();
        while(p1<n && p2<m) {
            if(series1[p1][0]<series2[p2][0]) {
                ans.push_back({series1[p1][0],series1[p1][1]+series2[p2][1]});
                p1++;
            } else if(series2[p2][0]<series1[p1][0]) {
                ans.push_back({series2[p2][0],series2[p2][1]+series1[p1][1]});
                p2++;
            } else {
                ans.push_back({series1[p1][0],series1[p1][1]+series2[p2][1]});
                p1++;
                p2++;
            }
        }
        while(p1<n) ans.push_back(series1[p1++]);
        while(p2<m) ans.push_back(series2[p2++]);
        return ans;
    }
};