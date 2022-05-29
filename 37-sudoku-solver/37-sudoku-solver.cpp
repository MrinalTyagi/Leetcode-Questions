class Solution {
public:
    
    bool isSafe(int row, int col, vector<vector<char>> &board, char val) {
        for(int i = 0; i < board.size(); i++) {
            if(board.at(row).at(i) == val) {
                return false;
            }
            if(board.at(i).at(col) == val) {
                return false;
            }
        }
        for(int i = (row / 3) * 3; i < ((row / 3) * 3) + 3; i++) {
            for(int j = (col / 3) * 3; j < ((col / 3) * 3) + 3; j++) {
                if(board.at(i).at(j) == val) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>> &board) {
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if(board.at(i).at(j) == '.') {
                    for(int k = 1; k <= 9; k++) {
                        if(isSafe(i, j, board, (char)(k + '0'))) {
                            board.at(i).at(j) = (char)(k + '0');
                            bool res = helper(board);
                            if(res == true) {
                                return true;
                            }
                            board.at(i).at(j) = '.';
                        }   
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};