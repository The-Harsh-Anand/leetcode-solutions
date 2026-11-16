class Solution {
public:
    string digitSum(string s, int k) {
        string temp=s,st="";
        int sum=0;
        while(temp.length()>k) {
            int l=temp.length();
            for(int i=0;i<l;i++) {
                sum+=(temp[i]-'0');
                if((i+1)%k==0) {
                    st+=to_string(sum);
                    cout<<to_string(sum)<<" ";
                    sum=0;
                }
            }
            if(l%k!=0) st+=to_string(sum);
            sum=0;
            temp=st;
            st="";
        }
        return temp;
    }
};