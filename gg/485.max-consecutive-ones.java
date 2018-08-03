class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        if(nums == null || nums.length == 0) return 0;

        int max = 0, count = 0;
        for(int i = 0; i < nums.length; i++) {
            count = nums[i] == 1 ? count + 1 : 0;
            if(count > max) max = count;
        }

        return max;
    }
}