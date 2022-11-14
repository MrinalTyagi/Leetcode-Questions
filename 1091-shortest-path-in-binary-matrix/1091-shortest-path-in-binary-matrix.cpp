class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        queue<pair<int, pair<int, int>>> pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;
        if(grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) {
            return -1;
        }
        while(!pq.empty()) {
            int d = pq.front().first;
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            pq.pop();
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int nRow = row + i;
                    int nCol = col + j;
                    if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == 0 && d + 1 < dist[nRow][nCol]) {
                        dist[nRow][nCol] = d + 1;
                        pq.push({dist[nRow][nCol], {nRow, nCol}});
                    }
                }
            }
        }
        if(dist[grid.size() - 1][grid[0].size() - 1] == INT_MAX) {
            return -1;
        } 
        return dist[grid.size() - 1][grid[0].size() - 1];
    }
};