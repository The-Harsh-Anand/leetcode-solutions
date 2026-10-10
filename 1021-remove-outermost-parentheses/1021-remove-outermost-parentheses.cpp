class Solution {
public:
    string removeOuterParentheses(string s) {
        int sw=0;
        int i;
        int n=s.length();
        string temp="";
        vector<string> p;
        for(i=0;i<n;i++) {
            if(s[i]=='(') {
                if(sw!=0)
                  temp+=s[i];
                sw++;
            }
            else {
                sw--;
                if(sw!=0)
                 temp+=s[i];
            }
        }
        return temp;
    }
};