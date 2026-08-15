class Solution {
public:
    int isok(string& s) {
        int l=0,r=s.length()-1;
        int eff=0;
        while(l<=r) {
            eff += min(abs(s[l]-s[r]),26-abs(s[l]-s[r]));
            l++;
            r--;
        }
        return eff;
    }
    int minOperations(string s) {
        int i,n=s.length();
        int mineff=INT_MAX,eff=0;
        mineff = isok(s);
        string st=s,st2;
        for(i=0;i<n;i++) {
            st2 = st[0];
            st.erase(0,1);
            st+=st2;
            eff = (i+1)+isok(st);
            cout<<eff<<" ";
            mineff = min(mineff,eff);
        }
        return mineff;
    }
};