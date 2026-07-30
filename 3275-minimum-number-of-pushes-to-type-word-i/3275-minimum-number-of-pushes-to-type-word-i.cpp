class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int x = n/8, r = n%8;
        int ans = 8*(x*(x+1))/2+(x+1)*r;
        return ans; 
    }
};