// time complexity: O(k*log(k))
// space complexity: O(k)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        if(nums1.empty() || nums2.empty())
            return ret;

        auto comp = [&nums1, &nums2](vector<int> a, vector<int> b) {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        int size1 = nums1.size();
        for(int i=0; i < min(k, size1); ++i) {
            pq.push({i, 0});
        }

        while(k-- > 0 && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ret.push_back(curr);
            if(curr[1]+1 == nums2.size()) continue;
            pq.push({curr[0], curr[1]+1});
        }

        for(int i=0; i < ret.size(); ++i) {
            ret[i][0] = nums1[ret[i][0]];
            ret[i][1] = nums2[ret[i][1]];
        }

        return ret;
    }
};

// time complexity: O(m*n*log(k))
// space complexity: O(k)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 <= 0 || size2 <= 0 || k <= 0)
            return result;

        auto comp = [](vector<int> a, vector<int> b) {
            return a[0] + a[1] < b[0] + b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);

        for(int i = 0; i < min(size1, k); i++) {
            for(int j = 0; j < min(size2, k); j++) {
                if(que.size() < k) {
                    que.push({nums1[i], nums2[j]});
                }
                else {
                    if (nums1[i] + nums2[j] < que.top()[0] + que.top()[1]) {
                        que.pop();
                        que.push({nums1[i], nums2[j]});
                    }
                }
            }
        }

        while (!que.empty()) {
            result.push_back(que.top());
            que.pop();
        }

        return result;
    }
};
