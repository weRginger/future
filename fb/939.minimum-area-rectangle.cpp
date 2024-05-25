// Time O(n^2)
// Space O(n)
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
                
                if(x1 != x2 && y1 != y2) // Point A & B must form a diagonal of the rectangle.
                    if(point_set.find({x1, y2}) != point_set.end()
					   && point_set.find({x2, y1}) != point_set.end())
                        minimum_area = min( minimum_area , abs(x1-x2) * abs(y1-y2) ); // Store the minimum area possible
            }
        }
        return minimum_area != INT_MAX ? minimum_area : 0; // Return 0 if no rectangle exists
    }
};
