#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> paginate(string& input, int pageLength) {
        vector<string> ans;
        if(input.empty()) {
            return ans;
        }
        vector<string> words = getWords(input);
        vector<string> subWords;
        int length = 0;
        for(auto w : words) {
            if(w.size() > pageLength) {
                cout << "Input word larger than page length, ERROR!" << endl;
                return ans; // error actually
            }
            if(w.size() + length <= pageLength) {
                subWords.push_back(w);
                length += w.size() + 1;
            }
            else {
                ans.push_back(wordsToPage(subWords));
                subWords.clear();
                length = 0;
                subWords.push_back(w);
                length += w.size() + 1;
            }
        }
        if(!subWords.empty()) {
            ans.push_back(wordsToPage(subWords));
        }
        return ans;
    }

private:
    vector<string> getWords(string& input) {
        vector<string> words;
        istringstream iss(input);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
    string wordsToPage(vector<string>& input) {
        int s = input.size();
        string res;
        int i;
        for(i = 0; i < s - 1; i++) {
            res += input[i] + ' ';
        }
        res += input[i];
        return res;
    }
};

int main() {
    Solution s;
    string input = "abcf defdf ad er foo ffffhh";
    vector<string> ans = s.paginate(input, 10);
    for(auto i : ans) {
        cout << i << endl;
    }
    return 0;
}