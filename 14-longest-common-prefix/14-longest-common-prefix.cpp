class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string rep = strs.at(0);
        int first = 0;
        for(int i = 1; i < strs.size(); i++) {
            int second = 0;
            while(first < rep.length() && second < strs.at(i).length() && strs.at(i).at(second) == rep.at(first)) {
                first++;
                second++;
            }
            rep = strs.at(i).substr(0, second);
            first = 0;
        }
        return rep;
    }
};