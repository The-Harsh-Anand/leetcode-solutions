class Solution {
public:
    void backtrack(vector<string>& ans, vector<string>& kp, string digits, int ind, string& s) {
        if(ind==digits.size()) {
            ans.push_back(s);
            return;
        }
        for(char c:kp[digits[ind]-'0']) {
            s.push_back(c);
            backtrack(ans,kp,digits,ind+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> keypad(10);
        keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int i,j;
        vector<string> ans;
        string s="";
        backtrack(ans,keypad,digits,0,s);
        return ans;
    }
};