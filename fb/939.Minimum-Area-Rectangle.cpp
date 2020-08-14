// Time O(N^2), where N is num of points
// Space O(N)
// For each pair of points in the array, consider them to be the long diagonal of a potential rectangle. 
// We can check if all 4 points are there using a Set.
// For example, if the points are (1, 1) and (5, 5), we check if we also have (1, 5) and (5, 1). If we 
// do, we have a candidate rectangle.
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;
        for (const auto& point: points)
            pointSet.insert(40001 * point[0] + point[1]);

        int ans = INT_MAX;
        for (int i = 0; i < points.size(); ++i)
            for (int j = i+1; j < points.size(); ++j) {
                // cannot be in the same line parallel to the x and y axes
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if (pointSet.count(40001 * points[i][0] + points[j][1]) &&
                            pointSet.count(40001 * points[j][0] + points[i][1])) {
                        ans = min(ans, abs(points[j][0] - points[i][0]) *
                                            abs(points[j][1] - points[i][1]));
                    }
                }
            }

        return ans < INT_MAX ? ans : 0;
    }
};
