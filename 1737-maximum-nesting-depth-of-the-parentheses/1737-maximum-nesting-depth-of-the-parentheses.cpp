class Solution {
public:
    int maxDepth(string s) {
        int n=s.length(),ans=0,curr=0,i;
        for(i=0;i<n;i++) {
            if(s[i]=='(') {
                curr++;
            } else if(s[i]==')') {
                curr--;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};