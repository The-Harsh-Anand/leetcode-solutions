class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smev=INT_MAX,smod=INT_MAX;
        for(int& x:nums1) {
            if(x%2==0) smev=min(smev,x);
            else smod = min(smod,x);
        }
        if(smod==INT_MAX || smev==INT_MAX) return true;
        //all odd: convert smev->odd <= smev>smod
        if(smev>smod) return true;
        return false;
    }
};