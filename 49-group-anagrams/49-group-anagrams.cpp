class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string x : strs) {
            string t = x;
            sort(t.begin(), t.end());
            map[t].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: map) {
            ans.push_back(x.second);
        }
        return ans;
    }
};