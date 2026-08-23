class Solution {
public:
    void helper(vector<string>& ans, string str, int n, int open,int closed) {
        if(open==closed&&open==n) {
            ans.push_back(str);
            return;
        } else if(closed>open) return;
        if(open<n) helper(ans,str+'(',n,open+1,closed);
        helper(ans,str+')',n,open,closed+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="(";
        helper(ans,str,n,1,0);
        return ans;
    }
};