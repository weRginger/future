// Kruskal’s Minimum Spanning Tree 
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
// Time O(n(logn))
// Space O(n)
class UF{
private:
    vector<int> parent;
    vector<int> size;
    int count;
public:
    UF(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
        count = n;
    }

    int find(int i){
        if(i != parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(int p, int q){
        int i = find(p);
        int j = find(q);
        if(size[i] > size[j]){
            parent[j] = i;
            size[i] += size[j];
        }else{
            parent[i] = j;
            size[j] += size[i];
        }
        count--;
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        };
        sort(connections.begin(), connections.end(), comp);
        int res = 0;
        UF uf(N);
        for(auto connect : connections){
            if(uf.find(connect[0]) != uf.find(connect[1])){
                uf.Union(connect[0], connect[1]);
                res += connect[2];
            }
            if(uf.getCount() == 1){
                return res;
            }
        }
        return -1;
    }
};
