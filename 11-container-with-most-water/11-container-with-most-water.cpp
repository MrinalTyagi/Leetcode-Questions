class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int start = 0, end = height.size() - 1;
        while(start < end) {
            int val = min(height.at(start), height.at(end)) * (end - start);
            res = max(res, val);
            if(height.at(start) < height.at(end)) {
                start++;
            } else {
                end --;
            }
        }
        return res;
    }
};