class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length(),len=target.length(),i,j;
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        for(char c:target) freq[c-'a']--;
        string ans="";
        for(i=len-1;i>=0;i--) {
            int cur = target[i]-'a';
            freq[cur]++;
            int flag=0;
            for(j=0;j<26;j++) {
                if(freq[j]<0) {
                    flag=1;
                    break;
                }
            }
            if(flag) continue;
            int nxt=-1;
            for(j=cur+1;j<26;j++) {
                if(freq[j]>0) {
                    nxt = j;
                    break;
                }
            }
            if(nxt==-1) continue;
            freq[nxt]--;
            ans = target.substr(0,i);
            ans+=('a'+nxt);
            for(j=0;j<26;j++) 
                ans.append(freq[j],'a'+j);
            return ans;
        }
        return "";
    }
};