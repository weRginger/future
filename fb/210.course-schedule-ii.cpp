// Time O(V+E)
// Space O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> neighbor;
        vector<int> degree(numCourses, 0);
        for(const auto& v : prerequisites) {
            degree[v[0]]++;
            neighbor[v[1]].push_back(v[0]);
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(degree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int out = q.front();
            q.pop();
            ans.push_back(out);
            for(auto n : neighbor[out]) {
                degree[n]--;
                if(degree[n] == 0)
                    q.push(n);
            }
        }
        
        if(ans.size() == numCourses)
            return ans;
        return {};
    }
};
