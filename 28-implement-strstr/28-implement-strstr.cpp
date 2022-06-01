class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) {
            return 0;
        }
        int n = haystack.length(), m = needle.length();
        for(int i = 0; i < n - m + 1; i++) {
            bool flag = true;
            for(int j = 0; j < m; j++) {
                if(haystack.at(i + j) != needle.at(j)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return i;
            }
        }
        return -1;
    }
};