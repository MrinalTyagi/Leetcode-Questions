class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;        
        for(int i = 0; i < path.length(); ) {
            if(path.at(i) == '/') {
                int j = i + 1;
                string t = "";
                while(j < path.length() && path.at(j) != '/') {
                    t += path.at(j);
                    j++;
                }
                i = j;
                if(t != "") {
                    if(t == ".") {
                        
                    } else if(t == "..") {
                        if(!s.empty()) {
                          s.pop_back();   
                        }
                    } else {
                        s.push_back(t);
                    }
                }
            }
        }
        string res = "";
        while(!s.empty()) {
            res += '/';
            res += s.front();
            s.pop_front();
        }
        if(res == "") {
            res += '/';
        }
        return res;
    }
};