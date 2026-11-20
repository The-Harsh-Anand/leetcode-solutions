class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),i,ans=0;
        vector<int> v={-1};
        for(i=0;i<n;i++) {
            if(s[i]=='(') v.push_back(i);
            else {
                v.pop_back();
                if(v.empty()) v.push_back(i);
                else ans=max(ans, i-v.back());
            }
        }
        return ans;
    }
};