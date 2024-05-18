// Time O(n)
// Space O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty())
            return 0;
        int l = 0;
        int r = height.size() - 1;
        int maxarea = INT_MIN;
        while(l < r) {
            maxarea = max(maxarea, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r])
                l++;
            else if(height[l] > height[r])
                r--;
            else {
                l++;
                r--;
            }
        }
        return maxarea;
    }
};
