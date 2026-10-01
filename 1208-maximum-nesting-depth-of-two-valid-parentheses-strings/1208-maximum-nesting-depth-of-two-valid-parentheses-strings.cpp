class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int i,n=seq.size(),currdep=0;
        vector<int> ans;
        for(i=0;i<n;i++) {
            if(seq[i]=='(') {
                currdep++;
                if(currdep%2==0) ans.push_back(0);
                else ans.push_back(1);
            }
            else {
                if(currdep%2==0) ans.push_back(0);
                else ans.push_back(1);
                currdep--;
            }
        }
        return ans;
    }
};