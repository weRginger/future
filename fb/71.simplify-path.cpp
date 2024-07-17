// Time O(n)
// Space O(n)
class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        // should not use stack since res needs to start from leftmost
        // see line 22
        vector<string> stk; 
        istringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if(tmp == "" or tmp == ".") continue;
            if(tmp == "..") {
                if(!stk.empty()) {
                    stk.pop_back();
                }
            }
            else {
                stk.push_back(tmp);
            }
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};
