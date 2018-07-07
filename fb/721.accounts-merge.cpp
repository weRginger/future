const int N = 1000 + 5;
int n, par[N];
int find(int x) {
    return par[x] == x ? x : (par[x] = find(par[x]));
}
void unit(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[x] = y;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        n = accounts.size();
        for (int i = 0; i < n; i++) par[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) if (!same(i, j)) {
                    for (int k = 1; k < accounts[i].size(); k++) for (int t = 1; t < accounts[j].size(); t++) {
                            if (accounts[i][k] == accounts[j][t]) unit(i, j);
                        }
                }
        }
        vector<set<string> > res;
        res.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = find(i);
            for (int j = 1; j < accounts[i].size(); j++) res[par[i]].insert(accounts[i][j]);
        }
        vector<vector<string> > ret;
        for (int i = 0; i < n; i++) if (par[i] == i) {
                vector<string> cur;
                cur.push_back(accounts[i][0]);
                for (auto str : res[i]) cur.push_back(str);
                ret.push_back(cur);
            }
        return ret;
    }
};