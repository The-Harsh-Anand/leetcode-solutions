class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0,ans=0;
        for(char& c:s) {
            if(c==')') bal--;
            else bal++;
            if(bal<0) {
                ans+=abs(bal);
                bal=0;
            }
        }
        if(bal>0) ans+=bal;
        return ans;
    }
};