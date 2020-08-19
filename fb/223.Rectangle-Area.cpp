// Time O(1)
// Space O(1)
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area1 = (C - A) * (D - B);
        long area2 = (G - E) * (H - F);
        int x1 = max(A, E);
        int x2 = max(x1, min(C, G));
        int y1 = max(B, F);
        int y2 = max(y1, min(D, H));
        return area1 + area2 - (x2 - x1) * (y2 - y1);
    }
};
