class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,n=height.size(),r=n-1,lMax=0,rMax=0,total=0;
        while(l<r) {
            lMax = max(lMax,height[l]);
            rMax = max(rMax,height[r]);

            if(lMax<rMax) {
                total+=lMax-height[l];
                l++;
            } else {
                total+=rMax-height[r];
                r--;
            }
        }
        return total;
    }
};