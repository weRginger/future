// Take away: c++ string constrcutor - string(size_t n, char c)
class Solution {
public:
    string toGoatLatin(string S) {
        if(S.empty()) return string{};
        istringstream iss(S);
        vector<string> vs;
        string s;
        while(iss >> s) {
            vs.push_back(s);
        }
        string ans = "";
        int size = vs.size();
        for(int i = 0; i < size; i++) {
            if(vs[i][0] == 'a' ||
                    vs[i][0] == 'e' ||
                    vs[i][0] == 'i' ||
                    vs[i][0] == 'o' ||
                    vs[i][0] == 'u' ||
                    vs[i][0] == 'A' ||
                    vs[i][0] == 'E' ||
                    vs[i][0] == 'I' ||
                    vs[i][0] == 'O' ||
                    vs[i][0] == 'U') {
                ans += vs[i] + "ma" + string(i + 1, 'a') + " "; // note the string constructor
            }
            else {
                ans += vs[i].substr(1) + vs[i].substr(0, 1) + "ma" + string(i + 1, 'a') + " ";
            }
        }
        return ans.substr(0, ans.size() - 1);
    }
};