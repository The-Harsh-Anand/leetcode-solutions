class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),i=0,j=0,len=0,maxlen=0;
        vector<int> hash(128,-1);
        while(j<n) {
            if(hash[s[j]]!=-1) {
                if(hash[s[j]]>=i) {
                    i = hash[s[j]]+1;
                }
            }
            len = j-i+1;
            maxlen = max(maxlen,len);
            hash[s[j]] = j;
            j++; 
        }
        return maxlen;
    }
};