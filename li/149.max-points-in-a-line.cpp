/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()<2) return points.size();
        int result=0;
        for(int i=0; i<points.size(); i++) {
            // need to use map instead of unordered_map
            // since pair cannot be keys in unordered_map without a comparator
            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0;
            for(int j=i+1; j<points.size(); j++) {
                if(points[j].x==points[i].x && points[j].y==points[i].y) {
                    overlap++;
                }
                else {
                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);
                    a/=gcd;
                    b/=gcd;
                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }
            }
            result=max(result, localmax+overlap+1);
        }
        return result;
    }

private:
    int GCD(int a, int b) {
        if(b==0) return a;
        return GCD(b, a%b);
    }
};
