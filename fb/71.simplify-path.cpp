// Time O(n)
// Space O(n)
class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        istringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." && !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};
