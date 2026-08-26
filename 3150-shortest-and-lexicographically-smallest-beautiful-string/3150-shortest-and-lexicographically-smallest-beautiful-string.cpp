class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // int i = 0, j = 0, n = s.length(), ctr = 0, len = 101;
        // string ans = s,str="";
        // while(j<n) {
        //     while (j < n && ctr <= k) {
        //         if (ctr == k && j - i + 1 < len) {
        //             len = j - i + 1;
        //             ans = str = s.substr(i,len);
        //         } 
        //         else if (ctr == k && j - i + 1 == len) {
        //             str = s.substr(i,len);
        //             ans = min(ans, str);
        //         }
        //         ctr += (s[j] - '0');
        //         str += s[j];
        //         j++;
        //     }
        //     ctr -= (s[i] - '0');
        //     i++;
        //     // if(ctr==k) {
        //     //     str = s.substr(i,len-1);
        //     //     ans = min(ans,str);
        //     // }
        // }
        // cout<<ctr;
        // if(ctr==k&& ans=="") return s; 
        // return ans;

        int i=0,j=0,n=s.length(),ctr=0,len=101;
        string str="",ans="";
        while(j<n) {
            ctr+=(s[j]-'0');

            while(i<n && ctr>k)  ctr-=(s[i++]-'0');
            while(ctr==k && s[i]=='0') i++;

            if(ctr==k) {
                str = s.substr(i,j-i+1);
                if(ans=="" || (j-i+1)<len || (j-i+1==len && str<ans)) {
                    ans = str;
                    len = j-i+1;
                }
            }
            j++;
        }
        return ans;
    }
};