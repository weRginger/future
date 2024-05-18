// Time O(log(min(x,y))
// Space O(1)
// source: https://www.youtube.com/watch?v=LPFhl65R7ww
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if nums1 length is greater than switch them so that nums1 is smaller than input2.
        // so the time complexity is O(log(min(x,y))
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int x = nums1.size();
        int y = nums2.size();

        int low = 0;
        int high = x;
        while(low <= high) {
            // partitionX and partitionY mean where we do the partition
            // For example, an array of 1, 5, 10, partitionX could be 0, 1, 2, 3,
            // which means we can partition before 1, between 1 and 5, between 5, 10 and after 10
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if((x + y) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if(maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
            }
        }
        // should never reach here
        return -1;
    }
};
