class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), sum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                int mx = INT_MIN, mn = INT_MAX;
                freq[s[j] - 'a']++;
                for (int k = 0; k < 26; k++) {
                    int diff = freq[k];
                    if (diff > 0) {
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }
                sum += (mx - mn);
            }
        }
        return sum;
    }
};