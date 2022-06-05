class Solution {
public:
    
    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        for(int i = 0; i < col; i++) {
            if(board.at(row).at(i) == 1) {
                return false;
            }
        }
        for(int i = 0; i < row; i++) {
            if(board.at(i).at(col) == 1) {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board.at(i).at(j) == 1) {
                return false;
            }
        }
        for(int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if(board.at(i).at(j) == 1) {
                return false;
            }
        }
        return true;
    }
     
    
    int helper(int col, vector<vector<int>> &board, int n) {
        if(col >= board.size()) {
            return 1;
        }
        int res = 0;
        for(int i = 0; i < board.size(); i++) {
            if(isSafe(i, col, board, n)) {
                board.at(i).at(col) = 1;
                res += helper(col + 1, board, n);
                board.at(i).at(col) = 0;
            }
        }
        return res;
    }
    
    
    int totalNQueens(int n) {
        vector<vector<int>> board;
        for(int i = 0; i < n; i++) {
            vector<int> a;
            for(int j = 0; j < n; j++) {
                a.push_back(0);
            }
            board.push_back(a);
        }
        return helper(0, board, n);
    }
};