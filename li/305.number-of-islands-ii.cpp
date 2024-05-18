class UnionFind {
public:
    UnionFind(int N) {
        count = 0;
        for (int i = 0; i < N; ++i) {
            parent.push_back(-1);
            rank.push_back(0);
        }
    }

    bool isValid(int i) const {
        return parent[i] >= 0;
    }

    void setParent(int i) {
        parent[i] = i;
        ++count;
    }

    int find(int i) { // path compression
        if (parents[i] == i) return parents[i];
        return parents[i] = find(parents[i]);
    }

    void Union(int x, int y) { // union with rank
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
            else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
            else {
                parent[rooty] = rootx;
                rank[rootx] += 1;
            }
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count; // # of connected components
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        UnionFind uf (m * n);

        for (auto& pos : positions) {
            int r = pos.first;
            int c = pos.second;
            // check pos's neighbors to see if they are in the existing islands or not
            vector<int> overlap; // how many existing islands overlap with 'pos'
            if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.push_back((r-1) * n + c);
            if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.push_back((r+1) * n + c);
            if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.push_back(r * n + c - 1);
            if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.push_back(r * n + c + 1);

            int index = r * n + c;
            uf.setParent(index);
            for (auto i : overlap) uf.Union(i, index);
            ans.push_back(uf.getCount());
        }

        return ans;
    }
};
