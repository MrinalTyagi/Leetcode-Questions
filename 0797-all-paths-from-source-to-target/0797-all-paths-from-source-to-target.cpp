class Solution {
public:
    
    void dfs(int index, vector<vector<int>> &graph, int dest, vector<vector<int>> &res, vector<bool> &visited, vector<int> &inter) {
        visited[index] = true;
        inter.push_back(index);
        if(index == dest) {
            visited[index] = false;
            res.push_back(inter);
            inter.pop_back();
            return;
        }
        for(auto x: graph[index]) {
            if(!visited[x]) {
                dfs(x, graph, dest, res, visited, inter);
            }
        }
        inter.pop_back();
        visited[index] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<vector<int>> res;
        vector<int> inter;
        dfs(0, graph, graph.size() - 1, res, visited, inter);
        return res;
    }
};