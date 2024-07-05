#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
  int getMaxPins(vector<vector<int>>& pins, int screen_len) {
    int max_pins = 0;
    auto comp = [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1] ? a[1] < b[1] : a[0] < b[0];
    };
    sort(pins.begin(), pins.end(), comp);
    auto comp_min_heap = [](int a, int b) {
      return a > b;
    };
    priority_queue<int, vector<int>, decltype(comp_min_heap)> pq(comp_min_heap);
    for(auto i : pins) {
      int s_start = i[1] - screen_len;
      if (i[0] >= s_start) {
        pq.push(i[0]);
      }
      while(pq.top() < s_start) {
        pq.pop();
      }
      max_pins = max(max_pins, (int)pq.size());
    }
    return max_pins;
  }
};

int main() {
  vector<vector<int>> pins = {{1,4,0},{2,3,1},{4,8,1},{6,9,0}};
  vector<int> screen_lens = {5, 7, 10};
  vector<int> expected_pins = {2, 3, 4};
  Solution s = Solution();
  for(int i = 0; i < (int)screen_lens.size(); i++) {
    assert(s.getMaxPins(pins, screen_lens[i]) == expected_pins[i]);
  }
  return 0;
}
