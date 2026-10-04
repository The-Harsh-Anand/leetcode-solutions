class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length(),i,diff=0,count=0;
        // vector<vector<bool>> dp(n+1,vector<bool>(3,0));

        // for(i=0;i<n;i++) {

        // }
        // return check(s,n,0,diff);
        for(i=0;i<n;i++) {
            if(s[i]=='(') diff++;
            else if(s[i]==')') diff--;
            else count++;
            if(diff<0 && abs(diff)>count) return false;
        }
        diff=0; count=0;
        for(i=n-1;i>=0;i--) {
            if(s[i]=='(') diff--;
            else if(s[i]==')') diff++;
            else count++;
            if(diff<0 && abs(diff)>count) return false;
        }
        return true;
    }
    // bool check(string s, int n, int i, int diff) {
    //     while(i<n) {
    //         if(s[i]=='(') diff++;
    //         else if(s[i]==')') diff--;
    //         else break;
    //         i++;
    //     }
    //     if(diff<0) return false;
    //     else if(i==n) return diff==0;
    //     return check(s,n,i+1,diff+1) || check(s,n,i+1,diff-1) || check(s,n,i+1,diff);
    // }
};