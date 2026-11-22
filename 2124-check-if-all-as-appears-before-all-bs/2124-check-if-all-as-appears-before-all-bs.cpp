class Solution {
public:
    bool checkString(string s) {
        int n=s.length(),i;
        bool flag=true;
        for(i=0;i<n;i++) {
            if(s[i]=='b' && flag) flag=false;
            if(!flag && s[i]=='a') return false;
        }
        return true;
    }
};