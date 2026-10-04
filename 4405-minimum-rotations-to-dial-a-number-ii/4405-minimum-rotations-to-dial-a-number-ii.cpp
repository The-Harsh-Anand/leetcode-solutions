class Solution {
public:
    int dist(char c, char k) {
        return min(abs(k-c),10-abs(k-c));
    }
    int minRotations(int n, string s) {
        int i,k;
        vector<int> pref(n,0),suff(n,0);
        pref[0] = dist('0',s[0]);
        for(i=1;i<n;i++) {
            pref[i]=pref[i-1]+dist(s[i],s[i-1]);
        }
        for(i=n-2;i>=0;i--) {
            suff[i]=suff[i+1]+dist(s[i],s[i+1]);
        }
        int ans=pref[n-1],cur;
        for(k=0;k<n;k++) {
            // i...n-1 reverses
            if(k==0) cur=dist('0',s[n-1])+suff[0];
            else cur=pref[k-1]+dist(s[k-1],s[n-1])+suff[k];
            ans = min(ans,cur);
        }
        return ans;
    }
};