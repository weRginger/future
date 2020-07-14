// Time O(AlogA), where A is the sum of accounts in the "accounts" input
// Space O(A) / 10000
class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string_view, int> ids;   // email to id
    unordered_map<int, string_view> names; // id to name
    vector<int> p(10000);
    iota(begin(p), end(p), 0); // initialize parent array
    
    function<int(int)> find = [&](int x) {
        if (p[x] != x) 
            p[x] = find(p[x]);
        return p[x];
    };
    
    auto getIdByEmail = [&](string_view email) {
        auto it = ids.find(email);
        if (it == ids.end()) {
            int id = ids.size();
            return ids[email] = id;
        }
        return it->second;
    };
    
    auto Union = [&](int id1, int id2) {
        p[find(id1)] = find(id2);
    };
 
    for (const auto& account : accounts) {      
        int id = getIdByEmail(account[1]);
        for (int i = 2; i < account.size(); ++i)
            Union(id, getIdByEmail(account[i]));
      
        // since all same accounts would have the same name,
        // we only need to store parentId -> name to the map
        names[find(id)] = string_view(account[0]);
    }
 
    unordered_map<int, set<string>> mergered;
    for (const auto& account : accounts)
        for (int i = 1; i < account.size(); ++i) {
        int parentId = find(getIdByEmail(account[i]));
        mergered[parentId].insert(account[i]);
      }    
 
    vector<vector<string>> ans;
    for (const auto& kv : mergered) {
        vector<string> curr;
        curr.push_back(string(names[kv.first]));
        for(auto s : kv.second)
            curr.push_back(s);
        ans.push_back(curr);
    }
 
    return ans;
  }
};
