class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int i,n=position.size();
        vector<pair<int,int>> cars(n);
        for(i=0;i<n;i++) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        sort(cars.begin(),cars.end());
        stack<double> time;
        for(i=0;i<n;i++) {
            double t = (target-cars[i].first)/(cars[i].second*1.0);
            while(!time.empty() && t>=time.top()) time.pop();
            time.push(t);
        }
        return time.size();

    }
};