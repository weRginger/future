class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int pos = 0;
        while(true) {
            pos = partition(nums, l, r);
            if(pos == k - 1)
                return nums[pos];
            else if(pos > k - 1)
                r = pos - 1;
            else
                l = pos + 1;
        }
        return -1;
    }
};
