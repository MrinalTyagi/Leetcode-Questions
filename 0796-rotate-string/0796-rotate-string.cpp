class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) {
            return false;
        }
        int i = 0;
        for(; i < s.length(); i++) {
            if(s[i] == goal[0]) {
                bool flag = true;
                int first = i, second = 0;
                while(second < goal.length()) {
                    if(s[first] != goal[second]) {
                        flag = false;
                        break;
                    } else {
                        first = (first + 1) % s.length();
                        second++;
                    }
                }
                if(flag) {
                    return true;
                }
            }
        }
        return false;
    }
};