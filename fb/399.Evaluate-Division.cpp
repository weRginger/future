// Author: Huahua
// Runtime: 3 ms
// https://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/
// Time O(E*Q), where E is num of edges and Q is num of queries
// Time can be reduced to O(Q) if we use memoization 
// Space O(E)
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // g[A][B] = k -> A / B = k
        unordered_map<string, unordered_map<string, double>> g;        
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }
        
        vector<double> ans;
        for (const auto& query : queries) {
            const string& X = query[0];
            const string& Y = query[1];
            if (!g.count(X) || !g.count(Y)) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;            
            ans.push_back(divide(X, Y, g, visited));
        }
        return ans;
    }
private:
    // get result of A / B
    double divide(const string& A, const string& B, 
                  unordered_map<string, unordered_map<string, double>>& g,
                  unordered_set<string>& visited) {        
        if (A == B) return 1.0;
        visited.insert(A);
        for (const auto& pair : g[A]) {
            const string& C = pair.first;
            if (visited.count(C)) continue;
            double d = divide(C, B, g, visited); // d = C / B
            // A / B = C / B * A / C
            if (d > 0) return d * g[A][C];
        }        
        return -1.0;
    }
};
