class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0,bal=0,i,n=s.length();
        for(i=0;i<n;i++) {
            if(s[i]=='(') bal++;
            else {
                bal--;
                if(s[i-1]=='(') ans+=1<<bal;
            }
        }
        return ans;
    }
};