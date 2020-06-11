// Time O(n)
// Space O(1) since at most 26 chars
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;

        // this lets us keep track of what's in our solution in O(1) time
        unordered_set<char> seen;

        // this will let us know if there are any more instances of s[i] left in s
        unordered_map<char, int> last_occurrence;
        for(int i = 0; i < s.length(); i++) last_occurrence[s[i]] = i;

        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            // we can only try to add c if it's not already in our solution
            // this is to maintain only one of each character
            if (seen.find(c) == seen.end()){
                // if the last letter in our solution:
                //     1. exists
                //     2. is greater than c so removing it will make the string smaller
                //     3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while(!stk.empty() && c < stk.top() && last_occurrence[stk.top()] > i){
                    char tmp = stk.top();
                    stk.pop();
                    seen.erase(tmp);
                }
                seen.insert(c);
                stk.push(c);
            }
        }
    string res;
    while(!stk.empty()) {
        char c = stk.top();
        stk.pop();
        res.insert(res.begin(), c);
    }
    return res;
    }
};
