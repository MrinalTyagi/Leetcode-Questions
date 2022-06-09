class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<int> dq;
        unordered_map<int, int> map;
        int count = 0;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            dq.push_back(s.at(i));
            map[s.at(i)]++;
            count++;
            while(!dq.empty() && map[s.at(i)] != 1) {
                int front = dq.front();
                map[front]--;
                dq.pop_front();
                count--;
            }

            res = max(res, count);
        }
        return res;
    }
};