// Time O(n)
// Space O(1)
// Author Ziqi
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int monotonic = 0; // 0 not know; 1 is asc; -1 is dec
        for(int i = 1; i < A.size(); i++) {
            if(A[i] == A[i-1]) continue;
            else if(A[i] > A[i-1]) {
                if(monotonic == 0) 
                    monotonic = 1;
                else if(monotonic == -1) 
                    return false;
            } else {
                if(monotonic == 0)
                    monotonic = -1;
                else if(monotonic == 1) 
                    return false;
            }
        }
        return true;
    }
};

// Time O(n)
// Space O(1)
// LC solution
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing = true;
        bool decreasing = true;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i+1])
                increasing = false;
            if (A[i] < A[i+1])
                decreasing = false;
        }

        return increasing || decreasing;
    }
};
