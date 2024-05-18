// Time O(n^2)
// Space O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 2) return points.size();
        int result = 0;
        for(int i = 0; i < points.size(); i++) {
            // need to use map instead of unordered_map
            // since pair cannot be keys in unordered_map without a comparator
            map<pair<int, int>, int> lines;
            int localmax = 0, overlap = 0;
            for(int j = i + 1; j < points.size(); j++) {
                if(points[j][0] == points[i][0] &&
                   points[j][1] == points[i][1]) {
                    overlap++;
                }
                else {
                    int a = points[j][0] - points[i][0];
                    int b = points[j][1] - points[i][1];
                    int gcd = GCD(a, b);
                    a /= gcd;
                    b /= gcd;
                    lines[{a, b}]++;
                    localmax = max(lines[{a, b}], localmax);
                }
            }
            // + 1 is to add the point in the outer loop
            result = max(result, localmax + overlap + 1); 
        }
        return result;
    }

private:
    int GCD(int a, int b) {
        if(b == 0) return a;
        return GCD(b, a % b);
    }
};
