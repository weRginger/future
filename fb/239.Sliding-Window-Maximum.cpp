// Source https://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
// Time O(n)
// Space O(k)
class MonotonicQueue {
public:
  void push(int e) {
    while(!data_.empty() && e > data_.back()) data_.pop_back();
    data_.push_back(e);
  } 
  
  void pop() {
    data_.pop_front();
  }
  
  int max() const { return data_.front(); }
private:
  deque<int> data_;
};
 
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue q;
    vector<int> ans;
        
    for (int i = 0; i < nums.size(); ++i) {
      q.push(nums[i]);
      if (i - k + 1 >= 0) {
        ans.push_back(q.max());
        if (nums[i - k + 1] == q.max()) q.pop();
      }      
    }
    return ans;
  }
};

// BST/max heap
// Time O((n – k + 1) * logk)
// Space O(k)
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if (nums.empty()) return ans;
    multiset<int> window(nums.begin(), nums.begin() + k - 1);
    for (int i = k - 1; i < nums.size(); ++i) {
      window.insert(nums[i]);
      ans.push_back(*window.rbegin());
      if (i - k + 1 >= 0)
        window.erase(window.equal_range(nums[i - k + 1]).first);      
    }
    return ans;
  }
};
