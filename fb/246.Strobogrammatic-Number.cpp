// Time O(n)
// Space O(1)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        const unordered_map<char, char> um = {{'0', '0'},
                                              {'1', '1'},
                                              {'6', '9'},
                                              {'8', '8'},
                                              {'9', '6'}};
        for(int i = 0; i < (num.size() + 1) / 2; i++) { // must check the middle index, note the i end condition
            if(!um.count(num[i])) 
                return false;
            if(um.at(num[i]) != num[num.size()-1-i]) 
                return false;
        }
        return true;
    }
};
