class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> arr[numCourses];
        for(auto x: prerequisites) {
            int s = x[1];
            int d = x[0];
            arr[s].push_back(d);
        }
        queue<int> q;
        vector<int> indeg(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto x: arr[i]) {
                indeg[x]++;
            }
        }
        for(int i = 0; i < indeg.size(); i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(auto x: arr[temp]) {
                indeg[x]--;
                if(indeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        if(res.size() == numCourses) {
            return res;
        } else {
            vector<int> r;
            return r;
        }
    }
};