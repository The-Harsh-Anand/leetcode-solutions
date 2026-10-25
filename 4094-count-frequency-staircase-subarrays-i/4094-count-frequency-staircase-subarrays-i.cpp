class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size(),i,j,x;
        vector<int> freq(100001,0),ord(100001,0);
        int ans = 0;
        for(i=0;i<n;i++) {
            int ctr=0,valid=0;
            for(j=i;j<n;j++) {
                x = nums[j];
                if(freq[x]==0) {
                    ctr++;
                    ord[x]=ctr;
                    freq[x]++;
                    if(freq[x]==ord[x]) valid++;
                } else {
                    if(freq[x]==ord[x]) valid--;
                    freq[x]++;
                    if(freq[x]==ord[x]) valid++;
                }
                if(valid==ctr) ans++;
            }
            for(j=i;j<n;j++) {
                freq[nums[j]]=0;
            }
        }
        return ans;
    }
};