// Time O(1)
// Space O(1)
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long area1 = (ax2 - ax1) * (ay2 - ay1);
        long area2 = (bx2 - bx1) * (by2 - by1);
        int x1 = max(ax1, bx1);
        int x2 = max(x1, min(ax2, bx2));
        int y1 = max(ay1, by1);
        int y2 = max(y1, min(ay2, by2));
        return area1 + area2 - (x2 - x1) * (y2 - y1);
    }
};
