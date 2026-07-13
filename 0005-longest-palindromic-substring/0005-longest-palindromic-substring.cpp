class Solution {
public:
    vector<int> helper(string s, int left, int right) {
        int i;
        while(left>=0 && right<s.length() && s[left]==s[right]) {
            left--;
            right++;
        }
        return {left+1,right-1};
    }
    string longestPalindrome(string s) {
        int i,n=s.length(),lMax=0,rMax=0,maxlen=0,len;
        vector<int> pos;
        string res;
        for(i=0;i<n;i++) {
            pos = helper(s,i,i);
            len = pos[1]-pos[0]+1;
            if(len>maxlen) {
                lMax = pos[0];
                rMax=pos[1];
                maxlen=len;
            }
            pos = helper(s,i,i+1);
            len = pos[1]-pos[0]+1;
            if(len>maxlen) {
                lMax = pos[0];
                rMax=pos[1];
                maxlen=len;
            }
        }
        return s.substr(lMax,maxlen);
    }
};