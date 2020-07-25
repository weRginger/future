// Time O(n*log26)
// Space O(26)
class Solution {
public:
    string reorganizeString(string S) {
        int N = S.length();
        
        vector<int> count(26, 0);
        for(auto c: S) count[c-'a']++;
        
        auto comp = [](const pair<char,int>& a, const pair<char,int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)> pq(comp);

        for(int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                if (count[i] > (N + 1) / 2) return "";
                pq.push({(char) ('a' + i), count[i]});
            }
        }

        string ans;
        while(pq.size() >= 2) {
            auto max = pq.top(); pq.pop();
            auto next = pq.top(); pq.pop();
            ans += max.first;
            ans += next.first;
            if(--max.second > 0) pq.push(max);
            if(--next.second > 0) pq.push(next);
        }

        if(pq.size() > 0) 
            ans += pq.top().first;
        
        return ans;
    }
};
