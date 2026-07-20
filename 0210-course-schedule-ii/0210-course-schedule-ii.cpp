class Solution {
public:
    vector<int> seq;
    bool dfs(vector<vector<int>>& courses, vector<int>& vis, int node, vector<int>& path) {
        vis[node]=path[node]=1;
        for(auto x:courses[node]) {
            if(!vis[x]) {
                if(dfs(courses,vis,x,path)) {
                    return true;
                } 
                seq.push_back(x);
            } else if(path[x]) return true;
        }
        path[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        vector<int> vis(numCourses,0),path(numCourses,0);
        vector<vector<int>> courses(numCourses);
        int i,n=pr.size();
        for(auto x:pr)   courses[x[1]].push_back(x[0]);
        bool flag = false;
        for(i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(dfs(courses,vis,i,path)) {
                    flag=true;
                    break;
                }
                seq.push_back(i);
            }
        }
        if(flag) return {};
        reverse(seq.begin(),seq.end());
        return seq;
    }
};