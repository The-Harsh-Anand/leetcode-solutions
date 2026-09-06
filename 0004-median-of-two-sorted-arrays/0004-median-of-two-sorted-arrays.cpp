class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int i=0,j=0,m=a.size(),n=b.size();
        vector<int> uni;
        while(i<m && j<n) {
            uni.push_back(a[i]<=b[j]?a[i++]:b[j++]);
        }
        while(i<m) {
            uni.push_back(a[i]);
            i++;
        }
        while(j<n) {
            uni.push_back(b[j]);
            j++;
        }
        if((m+n)%2!=0) return uni[(m+n)/2];
        else return (uni[(m+n)/2]+uni[(m+n-1)/2])/2.0;
    }
};