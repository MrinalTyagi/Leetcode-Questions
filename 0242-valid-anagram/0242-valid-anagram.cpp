class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        vector<int> pre(26, 0);
        for(int i = 0; i < s.length(); i++) {
            pre[s[i] - 'a']++;
            pre[t[i] - 'a']--;
        }
        for(auto x: pre) {
            if(x != 0) {
                return false;
            }
        }
        return true;
    }
};