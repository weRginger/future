// bfs
// Time O(E+V)
// Space O(E+V)
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& e: edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        queue<int> q;
        vector<bool> v(n, false);
        int ans=0;
        for (int i=0; i<n; ++i) {
            if (v[i]) continue;
            ans++;
            q.push(i);
            while (!q.empty()) {
                auto curr=q.front();
                q.pop();
                v[curr]=true;
                for (auto nei: graph[curr])
                    if (!v[nei])
                        q.push(nei);
            }
        }
        return ans;
    }
};

// union-find
// Time O(E+V)
// Space O(V)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            parents.push_back(i);
            ranks.push_back(0);
        }
        for (auto i : edges) {
            unionByRank(i[0], i[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == parents[i]) {
                ans++;
            }
        }
        return ans;
    }
    
private:
    vector<int> parents;
    vector<int> ranks;
    
    // path compression
    int find (int i) {
        if (parents[i] == i) return parents[i];
        return parents[i] = find(parents[i]);
    }
    
    // union by rank
    void unionByRank(int e0, int e1) {
        int x = find(e0);
        int y = find(e1);
        if(x != y) {
            if (ranks[x] > ranks[y]) parents[y] = x;
            else if (ranks[x] < ranks[y]) parents[x] = y;
            else {
                parents[x] = y;
                ranks[y]++;
            }
        }
    }
};

// dfs
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& e: edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        stack<int> s;
        vector<bool> v(n, false);
        int ans=0;
        for (int i=0; i<n; ++i) {
            if (v[i]) continue;
            ans++;
            s.push(i);
            while (!s.empty()) {
                auto curr=s.top();
                s.pop();
                v[curr]=true;
                for (auto nei: graph[curr])
                    if (!v[nei])
                        s.push(nei);
            }
        }
        return ans;
    }
};
