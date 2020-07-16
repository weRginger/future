// Topological sorting using BFS, details see https://leetcode.com/problems/alien-dictionary/solution/
// Time O(C), where C be the total length of all the words in the input list, added together.
// Space O(1), since at most 26 letters
class Solution {
public:
    string alienOrder(vector<string> &words) {
        if(words.empty()) 
            return "";
        
        string ans;
        unordered_map<char, vector<char>> graph; // directed graph
        unordered_map<char, int> degree; // incoming degree
        
        if (!buildGraph(words, graph, degree)) 
            return "";
        
        // topological sorting
        queue<char> q;
        for(const auto& p: degree) {
            if(0 == p.second) q.push(p.first);
        }

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(const auto& vv : graph[v]) {
                degree[vv]--;
                if(0 == degree[vv]) q.push(vv);
            }
        }

        for(auto d: degree) { // more edges after topo sort -> circle
            if(d.second > 0) return "";
        }

        return ans;
    }

    bool buildGraph(const vector<string>& words, 
                    unordered_map<char, vector<char>>& graph, 
                    unordered_map<char, int>& degree) {
        for(auto w: words)
            for(auto c: w) degree[c] = 0;

        for(int i = 1; i < words.size(); i++) {
            string pre = words[i - 1], cur = words[i];
            int pre_sz = pre.size(), cur_sz = cur.size(), j = 0;

            while(j < pre_sz && j < cur_sz && pre[j] == cur[j]) {
                j++;
            }
            if(j < pre_sz && j == cur_sz) return false; // e.g. “eb” appears before “e” is invalid
            if(j < cur_sz && j < pre_sz) {
                graph[pre[j]].push_back(cur[j]); // add directed edge to graph
                degree[cur[j]]++;
            }
        }

        return true;
    }
};
