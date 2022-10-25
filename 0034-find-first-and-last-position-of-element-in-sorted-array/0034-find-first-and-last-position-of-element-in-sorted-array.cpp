class Solution {
public:
    int starting(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if(nums[mid] == target) {
                if(mid == 0 || nums[mid - 1] != nums[mid]) {
                    return mid;
                } else {
                    end = mid - 1;   
                }
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    int ending(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if(nums[mid] == target) {
                if(mid == nums.size() - 1 || nums[mid + 1] != nums[mid]) {
                    return mid;
                } else {
                    start = mid + 1;
                }
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(starting(nums, target));
        res.push_back(ending(nums, target));
        return res;
    }
};