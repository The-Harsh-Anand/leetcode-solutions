class Solution {
public:
    int minChanges(string s) {
        int n=s.length(),i,ctr=0;
        for(i=0;i<n;i+=2) {
            if(s[i]!=s[i+1]) ctr++;
        }
        return ctr;
    }
};