// Time: O(n*log(n)
// Space: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        if(citations[0] == 0) return 0;
        int ans = 1;
        for(int i = 0; i < citations.size(); i++) {
            if(citations[i] >= ans) {
                ans++;
            }
        }
        return ans - 1;
    }
};

// Time: O(n)
// Space: O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n+1);
        // counting papers for each citation number
        for (auto c : citations)
            papers[min(n, c)]++;
        // finding the h-index
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k])
            k--;
        return k;
    }
};

