// Time O(n)
// Space O(1) if not counting return value
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int s = A.size();
        vector<int> ans(s);
        int start = 0, end = s - 1;
        int i = end; // insert position.
        while (start <= end) { // <  or <=  ?   be careful about ==
            int pow1 = A[start] * A[start];
            int pow2 = A[end] * A[end];
            if (pow1 > pow2) {
                ans[i--] = pow1;
                start++;
            } else {
                ans[i--] = pow2;
                end--;
            }
        }
        return ans;
    }
};
