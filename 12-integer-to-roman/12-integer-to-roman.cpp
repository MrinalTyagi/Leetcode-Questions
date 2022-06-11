class Solution {
public:
    string intToRoman(int num) {
        string t = "";
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> ch = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < val.size(); i++) {
            int v = num / val.at(i);
            if(v > 0) {
                int c = v * val.at(i);
                while(v--) {
                    t += ch.at(i);
                } 
                num = num % c;
            }
        }
        return t;
    }
};