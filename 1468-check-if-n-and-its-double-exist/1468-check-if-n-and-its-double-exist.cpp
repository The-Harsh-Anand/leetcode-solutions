class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int i,j,n=arr.size();
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++)
                if(i!=j && arr[i]==arr[j]*2) return true;
        }
        return false;
    }
};