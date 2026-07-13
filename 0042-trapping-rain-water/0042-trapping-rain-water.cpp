class Solution {
public:
    int trap(vector<int>& height) {
        long l=0,n=height.size(),r=n-1,lMax=0,rMax=0,total=0;
        while(l<r) {
            if(height[l]<=height[r]) {
                if(lMax<=height[l]) lMax=height[l];
                else total += (lMax-height[l]);
                l++;
            } else {
                if(rMax<=height[r]) rMax=height[r];
                else total += (rMax-height[r]);
                r--;
            }
        }
        return total;
    }
};