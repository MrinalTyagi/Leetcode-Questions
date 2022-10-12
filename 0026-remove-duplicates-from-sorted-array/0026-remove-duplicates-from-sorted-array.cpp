class Solution {
public:
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[count - 1]) {
                swap(nums[i], nums[count]);
                count++; 
            }
        }
        return count;
    }
};