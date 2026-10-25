class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size(),i,j,t,x;
        vector<int> freq(100001,0),ord(100001,0);
        long long K=0;
        while((K+1)*(K+2)/2<=n) K++;
        int ans = 0;
        for(i=0;i<n;i++) {
            int ctr=0,valid=0;
            for(j=i;j<n;j++) {
                x = nums[j];
                if(freq[x]==0) {
                    if(ctr==K) break;
                    ctr++;
                    ord[x]=ctr;
                    freq[x]++;
                    if(freq[x]==ord[x]) valid++;
                } else {
                    if(freq[x]>=ord[x]) break;
                    freq[x]++;
                    if(freq[x]==ord[x]) valid++;
                }
                if(valid==ctr) ans++;
            }
            for(t=i;t<j;t++) {
                freq[nums[t]]=0;
            }
        }
        return ans;
    }
};