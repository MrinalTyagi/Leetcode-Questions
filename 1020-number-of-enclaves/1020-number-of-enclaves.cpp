class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;  
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                visited[i][0] = true;
                q.push({i, 0});
            }  
            
            if(grid[i][n - 1] == 1) {
                visited[i][n - 1] = true;
                q.push({i, n - 1});
            } 
        }
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                visited[0][i] = true;
                q.push({0, i});
            }  
            if(grid[m - 1][i] == 1) {
                visited[m - 1][i] = true;
                q.push({m - 1, i});
            }
        }
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
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
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};