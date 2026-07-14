class Solution {
public:
    string convert(string s, int numRows) {
        int skip = numRows+(numRows-2),skip1=skip,skip2=0,j;
        if(skip==0) return s;
        int i,len=0,n=s.length();
        string st="";
        for(i=0;i<numRows;i++) {
            for(j=i;j<n;) {
                if(skip1!=0) {
                    st+=s[j];
                    j+=skip1;
                }
                if(skip2!=0 && j<n) {
                    st+=s[j];
                    j+=skip2;
                }
            }
            skip1-=2;
            skip2+=2;
        }
        return st;
    }
};