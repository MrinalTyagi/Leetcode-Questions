class Solution {
public:
    void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col) {
        if(board[row][col] == 'X') {
            return;
        }
        visited[row][col] = true;
        if(row - 1 >= 0 && !visited[row - 1][col]) {
            helper(board, visited, row - 1, col);
        }
        if(row + 1 < board.size() && !visited[row + 1][col]) {
            helper(board, visited, row + 1, col);
        }
        if(col - 1 >= 0 && !visited[row][col - 1]) {
            helper(board, visited, row, col - 1);
        }
        if(col + 1 < board[row].size() && !visited[row][col + 1]) {
            helper(board, visited, row, col + 1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            helper(board, visited, i, 0);
            helper(board, visited, i, board[0].size() - 1);
        }
        for(int j = 0; j < board[0].size(); j++) {
            helper(board, visited, 0, j);
            helper(board, visited, board.size() - 1, j);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};