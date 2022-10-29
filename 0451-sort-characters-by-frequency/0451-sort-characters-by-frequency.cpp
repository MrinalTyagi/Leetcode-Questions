class Solution {
public:
    string frequencySort(string s) {        
        vector<pair<int, char>> pre(256);
        for(int i = 0; i < 256; i++) {
            pair<int, char> p({0, (char)(i)});
            pre[i] = p;
        }
        for(int i = 0; i < s.length(); i++) {
            pre[s[i]].first++;
        }
        sort(pre.begin(), pre.end());
        string res = "";
        for(int i = pre.size() - 1; i >= 0; i--) {
            if(pre[i].first > 0) {
                for(int j = 0; j < pre[i].first; j++) {
                    res += pre[i].second;
                }
            }
        }
        return res;
    }
};