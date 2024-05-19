/*
https://leetcode.com/discuss/interview-question/451431/facebook-onsite-generate-random-max-index
Given an array of integers arr, randomly return an index of the maximum value seen by far.
Example:
Input: [11, 30, 2, 30, 30, 30, 6, 2, 62, 62]
Expected sample output: [0, 1, 1, 2, 3, 3, 3, 3, 8, 9]

Solution: reservoir sampling
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> maxRandomIndex(vector<int>& nums) {
        vector<int> ans;
        int max = INT_MIN;
        int maxIndex = -1;
        int count = 0;
        for (int i = 0; i < int(nums.size()); i++) {
          if (nums[i] > max) {
            max = nums[i];
            maxIndex = i;
            count = 1;
          } else if (nums[i] == max) {
            count++;
            // reservoir sampling to choose 1 random index among count up to now
            if (rand() % count == 0) {
              maxIndex = i;
            }
          }
          ans.push_back(maxIndex);
        }
        return ans;
    }
};

// To execute C++, please define "int main()"
int main() {
  srand(time(0));
  Solution sol = Solution();
  vector<int> nums{11, 30, 2, 30, 30, 30, 6, 2, 62, 62}; 
  vector<int> ans = sol.maxRandomIndex(nums);
  for(auto a : ans) {
    cout << a << " ";
  }
  cout << "done";
  return 0;
}
