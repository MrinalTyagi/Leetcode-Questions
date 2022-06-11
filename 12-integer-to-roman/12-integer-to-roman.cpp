class Solution {
public:
    string intToRoman(int num) {
        string t = "";
        vector<int> val = {1000, 500, 100, 50, 10, 5, 1};
        vector<char> ch = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        for(int i = 0; i < val.size(); i+=2) {
            int v = num / val.at(i);
            if(v > 0) {
                int c = v * val.at(i);
                if(v == 4) {
                    v -= 4;
                    t += ch.at(i);
                    t += ch.at(i - 1);
                } else if(v == 9) {
                    v -= 9;
                    t += ch.at(i);
                    t += ch.at(i - 2);
                } else if(v >= 5) {
                    v -= 5;
                    t += ch.at(i - 1);
                }
                string a(v, ch.at(i));
                t += a;
                num = num % (c);
            }
        }
        return t;
    }
};