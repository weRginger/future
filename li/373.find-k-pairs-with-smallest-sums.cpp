// time complexity: O(m*n*log(k))
// space complexity: O(k)
class Solution {
public:
    vector< pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector< pair<int, int>> result;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 <= 0 || size2 <= 0 || k <= 0)
            return result;

        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return a.first + a.second < b.first + b.second;
        };
        priority_queue<pair<int, int>, vector< pair<int, int>>, decltype(comp)> que(comp);

        for(int i = 0; i < min(size1, k); i++) {
            for(int j = 0; j < min(size2, k); j++) {
                if(que.size() < k) {
                    que.push(make_pair(nums1[i], nums2[j]));
                }
                else {
                    if (nums1[i] + nums2[j] < que.top().first + que.top().second) {
                        que.pop();
                        que.push(make_pair(nums1[i], nums2[j]));
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

// time complexity: O(k*log(k))
// space complexity: O(k)
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        if(nums1.empty() || nums2.empty())
            return ret;

        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        int size1 = nums1.size();
        for(int i=0; i < min(k, size1); ++i) {
            pq.push(make_pair(i, 0));
        }

        while(k-- > 0 && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ret.push_back(curr);
            if(curr.second+1 == nums2.size()) continue;
            pq.push(make_pair(curr.first, curr.second+1));
        }

        for(int i=0; i < ret.size(); ++i) {
            ret[i].first = nums1[ret[i].first];
            ret[i].second = nums2[ret[i].second];
        }

        return ret;
    }
};

