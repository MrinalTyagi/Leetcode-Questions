class Solution {
public:
    
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    int helper(int index, vector<int> &nums) {
        if(index >= nums.size()) {
            return 1;
        }
        int sum = 0;
        for(int i = index; i < nums.size(); i++) {
            swap(nums.at(index), nums.at(i));
            if(nums.at(index) % (index + 1) == 0 || (index + 1) % nums.at(index) == 0) {
                sum += helper(index + 1, nums);
            } 
            swap(nums.at(index), nums.at(i));
        }
        return sum;
    } 
    int countArrangement(int n) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        return helper(0, nums);
    }
};