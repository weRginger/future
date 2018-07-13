class Solution {
public:
    string alienOrder(vector<string> &words) {
        string ans;
        if(!words.size()) return ans;

        vector<vector<int>> graph(26, vector<int>()); // directed graph
        unordered_map<int, int> degree; // incoming degree
        if (!buildGraph(words, graph, degree)) return "";
        // topological sorting
        queue<int> Que;
        for(auto elem: degree) {
            if(!elem.second) Que.push(elem.first);
        }

        while(!Que.empty()) {
            int v = Que.front();
            Que.pop();
            ans.push_back(v + 'a');
            for(auto vv: graph[v]) {
                degree[vv]--;
                if(!degree[vv]) Que.push(vv);
            }
        }

        for(auto d: degree) { // more edges after topo sort -> circle
            if(d.second > 0) return "";
        }

        return ans;
    }

    bool buildGraph(vector<string> &words, vector<vector<int>> &graph, unordered_map<int, int> &degree) {
        for(auto w: words)
            for(auto c: w) degree[c - 'a'] = 0;

        for(int i = 1; i < (int)words.size(); i++) {
            string pre = words[i - 1], cur = words[i];
            int pre_sz = (int)pre.size(), cur_sz = (int)cur.size(), j = 0;

            while(j < pre_sz && j < cur_sz && pre[j] == cur[j]) {
                j++;
            }
            if(j < pre_sz && j == cur_sz) return false; // e.g. “eb” appears before “e” is invalid
            if(j < cur_sz && j < pre_sz) {
                graph[pre[j] - 'a'].push_back(cur[j] - 'a'); // add directed edge to graph
                degree[cur[j] - 'a']++;
            }
        }

        return true;
    }
};