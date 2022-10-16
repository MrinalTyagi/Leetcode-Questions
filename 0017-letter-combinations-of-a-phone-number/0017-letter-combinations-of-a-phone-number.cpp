class Solution {
public:
    
    string getValue(int n) {
        if(n == 2) {
            return "abc";
        } else if(n == 3) {
            return "def";
        } else if(n == 4) {
            return "ghi";
        } else if(n == 5) {
            return "jkl";
        } else if(n == 6) {
            return "mno";
        } else if(n == 7) {
            return "pqrs";
        } else if(n == 8) {
            return "tuv";
        } else if(n == 9) {
            return "wxyz";
        } else {
            return "";
        }
    }
    
    void helper(int index, string digits, vector<string> &res, string a) {
        if(index >= digits.length()) {
            res.push_back(a);
        }
        string dig = getValue(digits[index] - '0');
        for(int i = 0; i < dig.length(); i++) {
            a.push_back(dig[i]);
            helper(index + 1, digits, res, a);
            a.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits == "") {
            return res;
        }
        string a;
        helper(0, digits, res, a);
        return res;
    }
};