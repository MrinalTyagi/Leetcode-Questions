class Solution {
public:
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s.at(start) != s.at(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int count = 0;
        int start = 0, end = s.length() - 1;
        for(int i = 0, j = s.length() - 1; i<= j;) {
            if(s.at(i) != s.at(j)) {
                if(isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)) {
                    return true;
                } else {
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
};