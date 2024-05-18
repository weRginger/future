// Time: O(nlog(n))
// Space: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        sort(citations.begin(), citations.end(), greater<>());
        int size = citations.size();
        for (int i = 0; i < size; i++) {
            if (citations[i] < i + 1) {
                return i;
            }
        }
        return size;
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

