class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (char t : tasks) {
            counts[t - 'A']++;
        }
        priority_queue<int> pq;
        for (auto count : counts) {
            if(count)
                pq.push(count);
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};

// Author: Huahua
// Runtime: 56 ms
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const char task : tasks)
            ++count[task - 'A'];
        const int max_count = *max_element(count.begin(), count.end());
        size_t ans = (max_count - 1) * (n + 1);
        ans += count_if(count.begin(), count.end(),
        [max_count](int c) {
            return c == max_count;
        });
        return max(tasks.size(), ans);
    }
};