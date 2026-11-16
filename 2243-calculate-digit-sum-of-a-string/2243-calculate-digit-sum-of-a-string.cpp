class Solution {
public:
    string digitSum(string s, int k) {
        string temp=s,st="";
        while(temp.length()>k) {
            st="";
            int i,l=temp.length();
            int sum=0;
            for(i=0;i<l;i++) {
                sum+=(temp[i]-'0');
                if((i+1)%k==0) {
                    st+=to_string(sum);
                    cout<<to_string(sum)<<" ";
                    sum=0;
                }
            }
            if(i%k!=0) st+=to_string(sum);
            temp=st;
        }
        return temp;
    }
};