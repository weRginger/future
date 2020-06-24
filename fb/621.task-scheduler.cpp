// Time O(n)
// Space O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);
        for(auto t : tasks) {
            frequencies[t - 'A']++;
        }
        sort(frequencies.begin(), frequencies.end(), greater<>());
        // max frequency
        int f_max = frequencies[0];
        int idle_time = (f_max - 1) * n;
        for(int i = 1; i < frequencies.size() && idle_time > 0; ++i) {
            if(frequencies[i] == f_max)
                // idle_time = (f_max - 1) * n, but we need take one more slot after the last task 
                idle_time -= frequencies[i] - 1; 
            else
                idle_time -= frequencies[i]; 
        }
        // in case idle_time has turned into negative
        idle_time = max(0, idle_time);
        return idle_time + tasks.size();
    }
};
