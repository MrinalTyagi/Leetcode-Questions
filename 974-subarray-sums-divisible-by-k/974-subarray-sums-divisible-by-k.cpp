class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int val = 0; 
        int prevSum = 0;
        s[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            prevSum += nums.at(i);
            int a = prevSum % k;
            if(a < 0) a += k;
            if(s.count(a) > 0) val += s[a];
            s[a]++;
        }
        return val;
    }
};