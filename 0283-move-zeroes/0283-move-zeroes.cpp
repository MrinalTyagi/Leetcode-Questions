class Solution {
public:
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[count]);
                count++;
            }
        }
    }
};