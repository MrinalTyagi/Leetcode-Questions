class Solution {
public:
    
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    
    void reverse(vector<int> &arr, int start, int end) {
        while(start <= end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    
    bool check(vector<int>& nums) {
        int index = -1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) {
                index = i - 1;
                break;
            }
        }
        if(index != -1) {
            reverse(nums, 0, index);
            reverse(nums, index + 1, nums.size() - 1);
            reverse(nums, 0, nums.size() - 1);
        }

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
};