class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int> v(n, -1);
        for(auto p : edges) {
            int x = find(v, p.first);
            int y = find(v, p.second);
            if(x == y) {
                return false;
            }
            v[x] = y;
        }
        return true;
    }
private:    
    int find(vector<int>& v, int i) {
        if(v[i] == -1) return i;
        return find(v, v[i]);
    }
};
