class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        int size = S.size();
        helper(ans,S,0,size);
        return ans;
    }

private:
    void helper(vector<string>& vs,string& S,int p, int size) {
        if(p == size) {
            vs.push_back(S);
            return ;
        }
        if(S[p] >= '0' && S[p] <= '9') helper(vs,S,p+1, size);
        else if(S[p] >= 'a' && S[p] <= 'z') {
            helper(vs,S,p+1,size);
            S[p] += 'A'-'a';
            helper(vs,S,p+1,size);
        }
        else if(S[p] >= 'A' && S[p] <= 'Z') {
            helper(vs,S,p+1,size);
            S[p] += 'a'-'A';
            helper(vs,S,p+1,size);
        }
    }
};