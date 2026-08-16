class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(),m=station.size();
        if(n==1) return 0;
        int i=0,j=0;
        vector<int> left(n,-1),right(n,-1);
        while(i<n) {
            while(skill[i]!=station[j]) j++;
            left[i++]=j++;
        }
        i=n-1;j=m-1;
        while(i>=0) {
            while(skill[i]!=station[j]) j--;
            right[i--]=j--;
        }
        int gap=0,maxgap=0;
        for(i=1;i<n;i++) {
            maxgap = max({maxgap,right[i]-left[i-1]});
        }
        return maxgap;
    }
};