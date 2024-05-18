// Time O(n)
// Space O(1)
class Solution {
public:
  /*
  Dutch National Flag problem solution.
  */
  void sortColors(vector<int>& nums) {
    // for all idx < p0 : nums[idx < p0] = 0
    // curr is an index of element under consideration
    int p0 = 0, curr = 0;
    // for all idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};

// couting sort method: 2-pass
// Time O(n)
// Space O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> map(3, 0);
        for (int num : nums)
            map[num]++;
        int index = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < map[i]; j++)
                nums[index++] = i;
    }
};
