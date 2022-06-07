class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = n + m - 1; i >= n; i--){
            nums1.at(i) = nums1.at(i - n); 
        }
        int first = n, second = 0, third = 0;
        while(first < n + m && second < n) {
            if(nums1.at(first) < nums2.at(second)) {
                nums1.at(third++) = nums1.at(first++);
            } else {
                nums1.at(third++) = nums2.at(second++);
            }
        }
        while(second < n) {
            nums1.at(third++) = nums2.at(second++);
        }
    }
};