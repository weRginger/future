// Time O(n)
// Space O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int S = A.size();
        if(S == 0) return {};
        vector<int> ans(S, 0);
        int l = 0;
        int r = S - 1;
        for(int i = S - 1; i >=0; i--) {
            if(abs(A[r]) < abs(A[l])) {
                ans[i] = abs(A[l]) * abs(A[l]);
                l++;
            } else {
                ans[i] = abs(A[r]) * abs(A[r]);
                r--;
            }
        }
        return ans;
    }
};
