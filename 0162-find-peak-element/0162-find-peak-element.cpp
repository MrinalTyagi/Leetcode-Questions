class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return 0;
        } else if(nums.size() == 2) {
            if(nums.at(0) > nums.at(1)) {
                return 0;
            } else {
                return 1;
            }
        }
        int start = 0, end = nums.size() - 1;
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == nums.size() - 1 || nums[mid + 1] <= nums[mid])) {
                return mid;
            } else if(mid != 0 && nums[mid - 1] > nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return 0;
    }
};