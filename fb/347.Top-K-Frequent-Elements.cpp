// min-heap
// Time O(n*logk)
// Space O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for(auto num : nums)
            freqs[num]++;
        
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for(auto p : freqs) {
            if(pq.size() < k) {
                pq.push(p);
            } else {
                auto& min = pq.top();
                if(min.second < p.second) {
                    pq.pop();
                    pq.push(p);
                }
            }
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};

// Bucket sort
// Time O(max(max_freq, n))
// Space O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_freq = 1;
        for (const int num : nums)
            max_freq = max(max_freq, ++count[num]);
        unordered_map<int, vector<int>> buckets;
        for (const auto& kv : count)
            buckets[kv.second].push_back(kv.first);
        vector<int> ans;
        for (int i = max_freq; i >= 1; --i) {
            auto it = buckets.find(i);
            if (it == buckets.end()) continue;
            for(auto i : it->second) {
                ans.push_back(i);
                if(ans.size() == k) 
                    return ans;
            }
        }
        return ans;
    }
};

// quickselect
// Time O(n) on average
// Space O(n)
// LC answer
class Solution {
private:
    vector<int> unique;
    map<int, int> count_map;

public:
    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = count_map[unique[pivot_index]];
        // 1. Move the pivot to the end
        swap(unique[pivot_index], unique[right]);

        // 2. Move all less frequent elements to the left
        int store_index = left;
        for (int i = left; i <= right; i++) {
            if (count_map[unique[i]] < pivot_frequency) {
                swap(unique[store_index], unique[i]);
                store_index += 1;
            }
        }

        // 3. Move the pivot to its final place
        swap(unique[right], unique[store_index]);

        return store_index;
    }

    void quickselect(int left, int right, int k_smallest) {
        /*
        Sort a list within left..right till kth less frequent element
        takes its place. 
        */

        // base case: the list contains only one element
        if (left == right) return;

        int pivot_index = left + rand() % (right - left + 1);

        // Find the pivot position in a sorted list
        pivot_index = partition(left, right, pivot_index);

        //If the pivot is in its final sorted position
        if (k_smallest == pivot_index) {
            return;
        } else if (k_smallest < pivot_index) {
            // go left
            quickselect(left, pivot_index - 1, k_smallest);
        } else {
            // go right
            quickselect(pivot_index + 1, right, k_smallest);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // build hash map: element and how often it appears
        for (int n : nums) {
            count_map[n] += 1;
        }

        // array of unique elements
        int n = count_map.size();
        for (pair<int, int> p : count_map) {
            unique.push_back(p.first);
        }

        // kth top frequent element is (n - k)th less frequent.
        // Do a partial sort: from less frequent to the most frequent, till
        // (n - k)th less frequent element takes its place (n - k) in a sorted array.
        // All elements on the left are less frequent.
        // All the elements on the right are more frequent.
        quickselect(0, n - 1, n - k);
        // Return top k frequent elements
        vector<int> top_k_frequent(k);
        copy(unique.begin() + n - k, unique.end(), top_k_frequent.begin());
        return top_k_frequent;
    }
};
