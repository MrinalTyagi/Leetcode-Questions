class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.size() == 0) {
            return res;
        }
        for(int i = 0; i < matrix.at(0).size(); i++){
            vector<int> a;
            for(int j = 0; j < matrix.size(); j++){
                a.push_back(matrix.at(j).at(i));
            }
            res.push_back(a);
        }
        return  res;
    }
};