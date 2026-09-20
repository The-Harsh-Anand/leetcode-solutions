class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), i, j;
        sort(intervals.begin(), intervals.end());
        long long ctr = 0;
        for (i = 0; i < n; i++) {
            int x = intervals[i][0], y = intervals[i][1];
            int l = i, r = n - 1, m = 0;
            while (l <= r) {
                m = l + (r - l) / 2;
                int p = intervals[m][0], q = intervals[m][1];
                if (p <= y) l = m + 1;
                else if(p > y) r = m - 1;
            }
            ctr = ctr + (r-i);
        }
        return ctr;
    }
};