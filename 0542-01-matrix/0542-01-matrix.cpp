class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                } 
            }
        }
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int d = dist[row][col];
            q.pop();
            if(row - 1 >= 0 && d + 1 < dist[row - 1][col]) {
                q.push({row - 1, col});
                dist[row - 1][col] = d + 1;
            }
            if(row + 1 < mat.size() && d + 1 < dist[row + 1][col]) {
                q.push({row + 1, col});
                dist[row + 1][col] = d + 1;
            }
            if(col - 1 >= 0 && d + 1 < dist[row][col - 1]) {
                q.push({row, col - 1});
                dist[row][col - 1] = d + 1;
            }
            if(col + 1 < mat[row].size() && d + 1 < dist[row][col + 1]) {
                q.push({row, col + 1});
                dist[row][col + 1] = d + 1;
            }
        }
        return dist;
    }
};