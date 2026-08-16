class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int index=INT_MAX,mindist=INT_MAX,i,j,n=drones.size();
        int in;
        for(i=0;i<n;i++) {
            int dist = abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
            if(dist<=drones[i][2] && dist<mindist) {
                    index=i;
                    mindist = dist;
            } 
        }
        if(index==INT_MAX) return -1;
        return index;
    }
};