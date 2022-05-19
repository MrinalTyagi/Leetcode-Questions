class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(abs(nums.at(i)) - 1) < 0) {
                res.push_back(abs(nums.at(i)));
            }
            nums.at(abs(nums.at(i)) - 1) *= -1;
        }
        return res;
    }
};