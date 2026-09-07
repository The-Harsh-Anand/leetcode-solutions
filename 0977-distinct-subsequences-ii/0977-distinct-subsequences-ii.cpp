class Solution {
public:
    int distinctSubseqII(string s) {
        int i,n=s.length(),j,mod=1e9+7;
        long long ans=1,temp;
        vector<long long> st(26,0);
        for(i=1;i<=n;i++) {
            int c = s[i-1]-'a';
            temp=(ans*2+mod-st[c])%mod;
            st[c]=ans;
            ans=temp;
        }
        return (ans-1+mod)%mod;
    }
};