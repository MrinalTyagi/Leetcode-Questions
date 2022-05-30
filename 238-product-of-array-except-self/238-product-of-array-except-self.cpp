class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rightSum(nums.size());
        for(int j = nums.size() - 1; j >= 0; j--) {
            if(j == nums.size() - 1) {
                rightSum.at(j) = 1;
            } else {
                rightSum.at(j) = rightSum.at(j + 1) * nums.at(j + 1);
            }
        }
        int prev = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                prev = nums.at(i);
                nums.at(i) = 1;
            } else {
                int val = prev * nums.at(i - 1);
                prev = nums.at(i);
                nums.at(i) = val;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            nums.at(i) = nums.at(i) * rightSum.at(i);
        }
        return nums;
    }
};