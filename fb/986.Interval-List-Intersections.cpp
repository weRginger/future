// Time O(m+n)
// Space O(1)
// author: Ziqi
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        if(A.empty() || B.empty())
            return ans;
        int SA = A.size();
        int SB = B.size();
        
        for(int i = 0, j = 0; i < SA && j < SB;) {
            auto& a = A[i];
            auto& b = B[j];
            
            // no intersection
            if(a[1] < b[0]) {
                ++i;
                continue;
            }
            
            // no intersection
            if(b[1] < a[0]) {
                ++j;
                continue;
            }
            
            vector<int> tmp;
            tmp.push_back(max(a[0], b[0]));
            if(a[1] > b[1]) {
                tmp.push_back(b[1]);
                ++j;
            } else if(a[1] < b[1]) {
                tmp.push_back(a[1]);
                ++i;
            } else {
                tmp.push_back(b[1]);
                ++i;
                ++j;
            }
            ans.push_back(tmp);
        }
        
        return ans;
     }
};

// Time O(m+n)
// Space O(1)
// LC solution
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
          // Let's check if A[i] intersects B[j].
          // lo - the startpoint of the intersection
          // hi - the endpoint of the intersection
          int lo = max(A[i][0], B[j][0]);
          int hi = min(A[i][1], B[j][1]);
          if (lo <= hi)
            ans.push_back({lo, hi});

          // Remove the interval with the smallest endpoint
          if (A[i][1] < B[j][1])
            i++;
          else
            j++;
        }

        return ans;
    }
};
