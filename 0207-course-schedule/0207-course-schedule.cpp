class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        int i;
        for(auto &i:pr) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            for(auto &it: adj[n]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        for(auto &it: indegree) if(it>0) return false;
        return true;
    }
};