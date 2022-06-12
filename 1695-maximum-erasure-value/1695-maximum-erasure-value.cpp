class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cur = 0;
        vector<int> map(1e4 + 1, -1);
        int l = 0, sm = 0;
        for (int r = 0; r < n;) {
            if (map[nums[r]] == -1 or map[nums[r]] < l) {
                cur += nums[r];
                ans = max(ans, cur);
                map[nums[r]] = r;
                r++;
            }
            else {
                cur -= nums[l++];
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};