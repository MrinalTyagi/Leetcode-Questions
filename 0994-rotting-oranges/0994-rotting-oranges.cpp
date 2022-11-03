class Solution {
public:
    int helper(vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int count = 0;
        while(!q.empty()) {
            int size = q.size();
            if(size > 0) {
                count++;
            }
            for(int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                grid[row][col] = 2;
                q.pop();
                if(row - 1 >= 0 && !visited[row - 1][col] && grid[row - 1][col] == 1) {
                    q.push({row - 1, col});
                    visited[row - 1][col] = true;
                }
                if(row + 1 < grid.size() && !visited[row + 1][col] && grid[row + 1][col] == 1) {
                    q.push({row + 1, col});
                    visited[row + 1][col] = true;
                }
                if(col - 1 >= 0 && !visited[row][col - 1] && grid[row][col - 1] == 1) {
                    q.push({row, col - 1});
                    visited[row][col - 1] = true;
                }
                if(col + 1 < grid[row].size() && !visited[row][col + 1] && grid[row][col + 1] == 1) {
                    q.push({row, col + 1});
                    visited[row][col + 1] = true;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        if(count == 0) {
            return 0;
        }
        return count - 1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        return helper(grid, visited);
    }
};