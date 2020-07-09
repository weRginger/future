// Time - a lot, not sure...
// Space - a lot, not sure...
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n,n);   
    }
private:
    vector<string>helper(int n,int m) {
        if(n==0) 
            return vector<string>{""};
        if(n==1) 
            return vector<string> {"0","1","8"};

        vector<string> lastResult = helper(n-2, m);
        vector<string> currResult;

        for(auto s : lastResult) {
            if(n!=m) 
                currResult.push_back("0"+s+"0");

            currResult.push_back("1"+s+"1");
            currResult.push_back("6"+s+"9");
            currResult.push_back("8"+s+"8");
            currResult.push_back("9"+s+"6");
        }
        return currResult;
    }
};
