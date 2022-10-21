class Solution {
public:
    
    void dfs(int index, vector<vector<int>> &arr, vector<bool> &visited) {
        visited[index] = true;
        for(int i = 0; i < arr[index].size(); i++) {
            if(arr[index][i] == 1 && !visited[i]) {
                dfs(i, arr, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};