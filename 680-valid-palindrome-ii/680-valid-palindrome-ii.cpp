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
        while(start <= end) {
            if(s.at(start) != s.at(end)) {
                if(count == 0) {
                    if(isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1)) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
            start++;
            end--;
        }
        return true;
    }
};