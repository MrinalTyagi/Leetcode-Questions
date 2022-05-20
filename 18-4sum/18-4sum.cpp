class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int v = pow(10, 5);
            vector<vector<int> > res;
            if(nums.size() <= 3) {
                return res;
            } 
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 3; i++) {
                if(i > 0 && nums.at(i - 1) == nums.at(i)) {
        		    continue;
        	    }
                for(int j = i + 1; j < nums.size(); j++) {
                    if(j > i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    int start = j + 1, end = nums.size() - 1;
                    int t = target - nums[i] - nums[j];
                    while(start < end) {
                        int sum = nums[start] + nums[end];
                        if(t == sum) {
                            vector<int> a;
                            a.push_back(nums.at(i));
                            a.push_back(nums.at(j));
                            a.push_back(nums.at(start));
                            a.push_back(nums.at(end));
                            res.push_back(a);
                            while(start < end && nums[start] == nums[start + 1]) start++;
                            while(start < end && nums[end - 1] == nums[end]) end--;
                            start++;
                            end--;
                        } else if (t > sum) {
                            start++;
                        } else {
                            end--;
                        }
                    }
                }
            }
            return res;
    }
};