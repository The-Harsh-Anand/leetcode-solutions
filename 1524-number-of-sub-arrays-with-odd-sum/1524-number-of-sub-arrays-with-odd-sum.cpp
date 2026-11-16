class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod=1e9+7;
        int ans=0;
        int sum=0;
        int ev=1,od=0;
        int i,l=arr.size();
        for(i=0;i<l;i++) {
            sum+=arr[i];
            if(sum%2==0) {
                ans=(ans+od)%mod;
                ev++;
            }else {
                ans=(ans+ev)%mod;
                od++;
            }
        }
        return ans;
    }
};