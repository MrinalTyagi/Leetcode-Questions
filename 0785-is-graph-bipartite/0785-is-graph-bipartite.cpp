class Solution {
public:
    
    bool bipartitie(int index, vector<vector<int>> &arr, vector<int> &color) {
        queue<int> q;
        q.push(index);
        color[index] = 0;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(auto x: arr[temp]) {
                if(color[x] == -1) {
                    color[x] = 1 - color[temp];
                    q.push(x);
                } else if(color[x] == color[temp]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1 && !bipartitie(i, graph, color)) {
                return false;
            }
        }
        return true;
    }
};