class Solution {
public:
    static bool comp(int a, int b) {
        string as = to_string(a),bs=to_string(b);
        if(as+bs>bs+as) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        int i,n=nums.size();
        sort(nums.begin(),nums.end(),comp); 
        if(nums[0]==0) return "0";
        string s;
        for(i=0;i<n;i++) s+=to_string(nums[i]);
        return s;
    }
};