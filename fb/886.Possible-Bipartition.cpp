// BFS
// Time O(V+E)
// Space O(V+E)
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(N);
        for (const auto& d : dislikes) {
            g[d[0] - 1].push_back(d[1] - 1);
            g[d[1] - 1].push_back(d[0] - 1);
        }
        queue<int> q;
        vector<int> colors(N, 0);  // 0: unknown, 1: red, -1: blue
        for (int i = 0; i < N; ++i) {
            if (colors[i] != 0) continue;
            q.push(i);
            colors[i] = 1;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nxt : g[cur]) {
                    if (colors[nxt] == colors[cur]) return false;
                    if (colors[nxt] != 0) continue;
                    colors[nxt] = -colors[cur];
                    q.push(nxt);
                }
            }
        }    
        return true;
    }
};
