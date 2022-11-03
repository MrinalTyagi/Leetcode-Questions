class Solution {
public:
    
    void helper(vector<vector<int>> &image, vector<vector<bool>> &visited, int sr, int sc, int color) {
        int prev = image[sr][sc];
        visited[sr][sc] = true;
        image[sr][sc] = color;
        if(sr - 1 >= 0 && !visited[sr - 1][sc] && image[sr - 1][sc] == prev) {
            helper(image, visited, sr - 1, sc, color);
        }
        if(sr + 1 < image.size() && !visited[sr + 1][sc] && image[sr + 1][sc] == prev) {
            helper(image, visited, sr + 1, sc, color);
        }
        if(sc - 1 >= 0 && !visited[sr][sc - 1] && image[sr][sc - 1] == prev) {
            helper(image, visited, sr, sc - 1, color);
        }
        if(sc + 1 < image[sr].size() && !visited[sr][sc + 1] && image[sr][sc + 1] == prev) {
            helper(image, visited, sr, sc + 1, color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        helper(image, visited, sr, sc, color);
        return image;
    }
};