#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> t = nums;
        sort(nums.begin(), nums.end());
        vector<int> result;
        int i = 0, j = nums.size() - 1;
        vector<int>::iterator it;
        while(i <= j){
            int sum = nums.at(i) + nums.at(j);
            if(sum == target){
            	it = find(t.begin(), t.end(), nums[i]);
                result.push_back(it - t.begin());
                t[it - t.begin()] = INT_MIN;
                it = find(t.begin(), t.end(), nums[j]);
                result.push_back(it - t.begin());
                break;
            }else if(sum < target){
                i++;
            }else if(sum > target){
                j--;
            }
        }

        return result;
    }
};