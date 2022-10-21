class Solution {
public:
    
    bool bipartitie(int index, vector<vector<int>> &arr, vector<int> &color) {
        for(auto x: arr[index]) {
            if(color[x] == -1) {
                color[x] = 1 - color[index];
                if(!bipartitie(x, arr, color)) {
                    return false;
                }
            } else if(color[x] == color[index]) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                color[i] = 0;
                if(!bipartitie(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};