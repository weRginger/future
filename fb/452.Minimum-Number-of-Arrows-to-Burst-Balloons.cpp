// Time O(N*logN)
// Space O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end());
        int ans = 1;
        vector<int> intersect = points[0];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > intersect[1]) {
                ans++;
                intersect = points[i];
            } else {
                intersect[0] = points[i][0];
                intersect[1] = min(intersect[1], points[i][1]);
            }
        }
        return ans;
    }
};
