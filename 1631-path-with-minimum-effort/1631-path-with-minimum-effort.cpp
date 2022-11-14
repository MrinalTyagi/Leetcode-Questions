class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> dist(heights.size(), vector<int> (heights[0].size(), INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty()) {
            int diff = pq.front().first;
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            pq.pop();
            if(row - 1 >= 0) {
                if(max(diff, abs(heights[row - 1][col] - heights[row][col])) < dist[row - 1][col]) {
                    dist[row-1][col] = max(diff, abs(heights[row - 1][col] - heights[row][col]));
                    pq.push({dist[row-1][col], {row - 1, col}});
                }
            }
            if(row + 1 < heights.size()) {
                if(max(diff, abs(heights[row + 1][col] - heights[row][col])) < dist[row + 1][col]) {
                    dist[row+1][col] = max(diff, abs(heights[row + 1][col] - heights[row][col]));
                    pq.push({dist[row + 1][col], {row + 1, col}});
                }
            }
            if(col - 1 >= 0) {
                if(max(diff, abs(heights[row][col - 1] - heights[row][col])) < dist[row][col - 1]) {
                    dist[row][col - 1] = max(diff, abs(heights[row][col - 1] - heights[row][col]));
                    pq.push({dist[row][col - 1], {row, col - 1}});
                }
            }
            if(col + 1 < heights[0].size()) {
                if(max(diff, abs(heights[row][col + 1] - heights[row][col])) < dist[row][col + 1]) {
                    dist[row][col + 1] = max(diff, abs(heights[row][col + 1] - heights[row][col]));
                    pq.push({dist[row][col + 1], {row, col + 1}});
                }
            }
        }
        if(dist[heights.size() - 1][heights[0].size() - 1] == INT_MAX) {
            return -1;
        }
        return dist[heights.size() - 1][heights[0].size() - 1];
    }
};