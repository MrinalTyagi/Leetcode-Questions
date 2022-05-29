class Solution {
public:
    
    bool isSafe(int col, int row, vector<string> &board, int n) {
        for(int i = 0; i < col; i++) {
            if(board.at(row).at(i) == 'Q') {
                return false;
            }
        }
        for(int i = 0; i < row; i++) {
            if(board.at(i).at(col) == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board.at(i).at(j) == 'Q') {
                return false;
            }
        }
        for(int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if(board.at(i).at(j) == 'Q') {
                return false;
            }
        }
        return true;
    } 
    
    void helper(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(isSafe(col, i, board, n) && board.at(col).at(i) == '.') {
                board.at(i).at(col) = 'Q';
                helper(col + 1, board, ans, n);
                board.at(i).at(col) = '.';
            }
        }
        
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for(int i = 0; i < n; i++) {
            string a;
            for(int j = 0; j < n; j++) {
                a += '.';
            }
            board.push_back(a);
        }
        helper(0, board, ans, n);
        return ans;
    }
};