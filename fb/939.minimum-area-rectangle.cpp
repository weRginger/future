// Time O(n^2)
// Space O(n)
// For each pair of points in the array, consider them to be the long diagonal of a potential rectangle. 
// We can check if all 4 points are there using a Set.
// For example, if the points are (1, 1) and (5, 5), we check if we also have (1, 5) and (5, 1). If we 
// do, we have a candidate rectangle.
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> point_set; // Key => Integer | Value => Set
        
        for(auto& single_point: points)
            point_set.insert({single_point[0], single_point[1]}); 
			
        int minimum_area = INT_MAX;
        
        for(int i = 0; i < points.size(); i++) { 
            for(int j = i + 1; j < points.size(); j++) { 
                int x1 = points[i][0], y1 = points[i][1];  // Coordinates of Point A
		int x2 = points[j][0], y2 = points[j][1];  // Coordinates of Point B
                if(x1 != x2 && y1 != y2) { // the line of A and B could be a dot NOR parallel to x or y axis
                    if(point_set.find({x1, y2}) != point_set.end() && point_set.find({x2, y1}) != point_set.end()) {
                        minimum_area = min(minimum_area , abs(x1-x2) * abs(y1-y2)); // Store the minimum area possible
		    }
		}
            }
        }
        return minimum_area != INT_MAX ? minimum_area : 0; // Return 0 if no rectangle exists
    }
};

// Time O(N^2)
// Space O(N)
// could use some hashing trick to use unordered_set instead
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;
        for (const auto& point: points)
            pointSet.insert(40001 * point[0] + point[1]);

        int ans = INT_MAX;
        for (int i = 0; i < points.size(); ++i)
            for (int j = i+1; j < points.size(); ++j) {
                // cannot be in the same line parallel to the x or y axes
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
