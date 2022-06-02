class Solution {
public:
    
    void lps(string p, int *arr) {
        int i = 1, len = 0, n = p.length();
        arr[0] = 0;
        while(i < n) {
            if(p.at(i) == p.at(len)) {
                arr[i] = len + 1;
                i++;
                len++;
            } else {
                if(len == 0) {
                    arr[i] = 0;
                    i++;
                } else {
                    len = arr[len - 1];
                }
            }
        }
    }
    
    
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) {
            return 0;
        }
        int n = haystack.length(), m = needle.length();
        int arr[needle.length()];
        lps(needle, arr);
        int i = 0, j = 0;
        while(i < n) {
            if(haystack.at(i) == needle.at(j)) {
                i++;
                j++;
            }
            if(j == m) {
                return (i - j);
                j = arr[j - 1];
            } else if(i < n && haystack.at(i) != needle.at(j)) {
                if(j == 0) {
                    i++;
                } else {
                    j = arr[j - 1];
                }
            }
        }
        return -1;
    }
};