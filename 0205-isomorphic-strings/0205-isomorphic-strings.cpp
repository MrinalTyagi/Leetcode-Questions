class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> c, r;
        for(int i = 0; i < s.length(); i++) {
            if(c.count(t[i]) == 0 && r.count(s[i]) == 0) {
                c[t[i]] = s[i];
                r[s[i]] = t[i];
            }
        }
        string res = "";
        for(int i = 0; i < t.length(); i++) {
            res += c[t[i]];
        }
        return (s == res);
    }
};