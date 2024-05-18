// Time O(N)
// Space O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k %= N;
        reverse(nums, 0, N - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, N - 1);
    }
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
          int temp = nums[start];
          nums[start] = nums[end];
          nums[end] = temp;
          start++;
          end--;
        }
    }
};
