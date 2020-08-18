// Time O(n)
// Space O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;

        // walk up
        while (i+1 < N && A[i] < A[i+1])
            i++;

        // peak can't be first or last
        if (i == 0 || i == N-1)
            return false;

        // walk down
        while (i+1 < N && A[i] > A[i+1])
            i++;

        return i == N-1;
    }
};

// Time O(n)
// Space O(1)
// Author Ziqi
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int S = A.size();
        if(S < 3)
            return false;
        
        int inc = 0;
        for(int i = 1; i < S; i++) {
            if(A[i] == A[i-1]) {
                return false;
            }
            else if(A[i] > A[i-1]) {
                if(inc == 0)
                    inc = 1;
                else if(inc == -1)
                    return false;
            } else {
                if(inc == 0)
                    return false;
                else if(inc == 1)
                    inc = -1;
            }
        }
        return inc == -1;
    }
};
