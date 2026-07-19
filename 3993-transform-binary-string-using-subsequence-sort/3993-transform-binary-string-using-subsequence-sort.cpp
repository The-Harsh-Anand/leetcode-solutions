class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int i,n=s.length(),j,c1=0;
        vector<int> pref1(n,0);
        for(i=0;i<n;i++) {
            if(s[i]=='1') c1++;
            pref1[i]=c1;
        }
        int c0 = n-c1;
        vector<bool> ans(strs.size());
        for(i=0;i<strs.size();i++) {
            vector<int> hash(3,0);
            for(j=0;j<n;j++) {
                if(strs[i][j]=='0') hash[0]++;
                else if(strs[i][j]=='1') hash[1]++;
                else hash[2]++;
            }
            int diff1 = c1-hash[1],diff0 = c0-hash[0];
            if(diff1<0 || diff0<0) {
                ans[i]=false;
                continue;
            }
            int prefone=0;
            bool flag=true;
            for(j=0;j<n;j++) {
                if(strs[i][j]=='1') prefone++;
                else if(strs[i][j]=='?') {
                    hash[2]--;
                    if(diff1>hash[2]) {
                        prefone++;
                        diff1--;
                    }
                }

                if(prefone>pref1[j]) {
                    flag=false;
                    break;
                }
            }
            ans[i] = flag&& diff1==0;
        }
        return ans;
    }
};