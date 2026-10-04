class Solution {
public:
    int minRotations(string s) {
        int n=s.length(),i,j;
        string dial="0123456789";
        int p=0,count=0,key=0;
        for(i=0;i<n;i++) {
            key=s[i]-'0';
            count=count+min(abs(key-p),10-abs(key-p));
            p=key;
        }
        return count;
    }
};