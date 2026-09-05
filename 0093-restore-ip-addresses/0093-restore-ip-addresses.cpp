class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int blocks = 0, idx=0;
        string ip="";
        backtrack(s,ip,ans,idx,blocks);
        return ans;
    }
    void backtrack(string& s,string ip,vector<string>& ans, int idx, int blocks) {
        int n = s.length();
        if(idx==n && blocks==4) {
            ans.push_back(ip);
            return;
        } else if(blocks==4) return;
        if(ip!="") ip+='.';
        if(idx<n) backtrack(s,ip+s[idx],ans,idx+1,blocks+1);
        if(idx+1<n && s[idx]!='0') backtrack(s,ip+s.substr(idx,2),ans,idx+2,blocks+1);
        if(idx+2<n) {
            string temp = s.substr(idx,3);
            if(temp<="255" && temp[0]!='0')
              backtrack(s,ip+temp,ans,idx+3,blocks+1);
        }
    }
};