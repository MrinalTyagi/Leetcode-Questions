class Solution {
public:
    
    bool isSafe(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if(row >= grid.size() || row < 0) {
            return false;
        }
        if(col >= grid.at(row).size() || col < 0) {
            return false;
        }
        if(grid.at(row).at(col) == -1) {
            return false;
        }
        if(visited.at(row).at(col) == true) {
            return false;
        }
        return true;
    }
    
    int helper(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if(grid.at(row).at(col) == 2) {
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid.at(i).size(); j++) {
                    if(grid.at(i).at(j) == -1) {
                        continue;
                    }
                    if(grid.at(i).at(j) == 2) {
                        continue;
                    }
                    if(visited.at(i).at(j) == false) {
                        return 0;
                    }
                }
            }
            return 1;    
        }
        
        int sum = 0;
        if(isSafe(row, col - 1, grid, visited)) {
            visited[row][col] = true;
            sum += helper(row, col - 1, grid, visited);
            visited[row][col] = false;
        }
        if(isSafe(row, col + 1, grid, visited)) {
            visited[row][col] = true;
            sum += helper(row, col + 1, grid, visited);
            visited[row][col] = false;
        }
        if(isSafe(row - 1, col, grid, visited)) {
            visited[row][col] = true;
            sum += helper(row - 1, col, grid, visited);
            visited[row][col] = false;
        }
        if(isSafe(row + 1, col, grid, visited)) {
            visited[row][col] = true;
            sum += helper(row + 1, col, grid, visited);
            visited[row][col] = false;
        }
        return sum;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited;
        for(int i = 0; i < grid.size(); i++) {
            vector<bool> a ;
            for(int j = 0; j < grid.at(i).size(); j++) {
               a.push_back(false);
            }
            visited.push_back(a);
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.at(i).size(); j++) {
                if(grid.at(i).at(j) == 1) {
                    res += helper(i, j, grid, visited);
                    break;
                }
            }
        }
        return res;
    }
};