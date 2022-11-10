class Solution {
public:
    
    bool topoDFS(int index, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVis, vector<int> &res) {
        visited[index] = true;
        dfsVis[index] = true;
        for(auto x: graph[index]) {
            if(!visited[x]) {
                if(topoDFS(x, graph, visited, dfsVis, res)) {
                    return true;
                }
            } else {
                if(dfsVis[x]) {
                    return true;
                }
            }
        }
        dfsVis[index] = false;
        res.push_back(index);
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> dfsVis(graph.size(), false);
        vector<int> res;
        for(int i = 0; i < graph.size(); i++) {
            if(!visited[i]) {
                topoDFS(i, graph, visited, dfsVis, res);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};