class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(nums);
        for (int i = result.size() - 1; i >= 0; i--) {
            int pos = rand() % (i + 1);
            swap(result[pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
