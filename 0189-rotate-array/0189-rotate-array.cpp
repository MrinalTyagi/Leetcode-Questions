class Solution {
public:
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    
    void ro(vector<int> &arr, int start, int end) {
        while(start <= end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0) {
            return;
        }
        
        ro(nums, 0, nums.size() - k - 1);
        ro(nums, nums.size() - k, nums.size() - 1);
        ro(nums, 0, nums.size() - 1);
    }
};