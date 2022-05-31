class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int first = 0, second = 0;
        string res = "";
        char carry = '0';
        while(first < num1.length() && second < num2.length()) {
            int f = (int)((char)(num1.at(first)) - '0');
            int s = (int)((char)(num2.at(second)) - '0');
            int c = (int)(carry - '0');
            int data = f + s + c;
            res += (char)((f + s + c) % 10 + '0');
            carry = (char)((f + s + c) / 10 + '0');
            first++;
            second++;
        }
        while(first < num1.length() ) {
            int f = (int)((char)(num1.at(first)) - '0');
            int c = (int)(carry - '0');
            int data = f + c;
            res += (char)((f + c) % 10 + '0');
            carry = (char)((f + c) / 10 + '0');
            first++;
        }
        while(second < num2.length() ) {
            int s = (int)((char)(num2.at(second)) - '0');
            int c = (int)(carry - '0');
            int data = s + c;
            res += (char)((s + c) % 10 + '0');
            carry = (char)((s + c) / 10 + '0');
            second++;
        }
        while(carry != '0') {
            int c = (int)(carry - '0');
            int data = c;
            res += (char)((c) % 10 + '0');
            carry = (char)((c) / 10 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};