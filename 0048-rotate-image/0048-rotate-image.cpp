class Solution {
public:
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int k = 0; k < matrix.size(); k++) {
            for(int i = 0, j = matrix[k].size() - 1; i <= j; i++, j--) {
                swap(matrix[k][i], matrix[k][j]);
            }
        }
    }
};