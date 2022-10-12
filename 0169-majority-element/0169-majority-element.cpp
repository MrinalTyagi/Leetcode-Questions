class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, index = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[index]) {
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                index = i;
                count = 1;
            }
        }
        return nums[index];
    }
};