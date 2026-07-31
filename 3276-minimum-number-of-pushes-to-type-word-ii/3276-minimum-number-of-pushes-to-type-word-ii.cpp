class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        vector<int> hash(26,0);
        for(char c:word) hash[c-'a']++;
        sort(hash.rbegin(),hash.rend());
        int ctr=1,curr=1,count=0;
        for(int i=0;i<26;i++) {
            if(hash[i]==0) break;
            if(curr>8) {
                ctr++;
                curr%=8;
            }
            count+=(hash[i]*ctr);
            curr++;
        }
        return count;
    }
};