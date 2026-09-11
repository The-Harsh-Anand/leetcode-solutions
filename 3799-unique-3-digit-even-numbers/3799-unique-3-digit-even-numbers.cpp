class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> hash(10,0);
        int ans=0,i,j,k,n=digits.size();
        for(i=0;i<n;i++)   hash[digits[i]]++;
        for(i = 1; i < 10; i++) { 
            for(j = 0; j < 10; j++) {
                for(k = 0; k < 9; k += 2) {
                    ans += hash[i] > 0 &&
                           hash[j] > (i == j) &&
                           hash[k] > (i == k) + (j == k);
                }
            }
        }
        return ans;
    }
};