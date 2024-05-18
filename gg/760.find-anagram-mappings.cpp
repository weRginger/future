class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        if(A.empty() || B.empty()) return ans;
        unordered_map<int, vector<int>> mp;
        int size = B.size();
        for(int i = 0; i < size; i++) {
            mp[B[i]].push_back(i);
        }
        for(int i = 0; i < size; i++) {
            int idx = mp[A[i]].back();
            mp[A[i]].pop_back();
            ans.push_back(idx);
        }
        return ans;
    }
};