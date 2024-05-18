// Time O(M*N)
// Space O(M)
// 经典，多看！
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int maxarea = 0;
        vector<int> dp(matrix[0].size());

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                // update the state of this row's histogram using the 
                // last row's histogram by keeping track of the number
                // of consecutive ones
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update maxarea with the maximum area from this row's histogram
            maxarea = max(maxarea, leetcode84(dp));
        } 
        
        return maxarea;
    }
    
private:
    // Get the maximum area in a histogram given its heights
    int leetcode84(const vector<int>& heights) {
        // Ziqi: seems like we are maintaining a monotonic stack, 
        // i.e. smallest at the bottom and largest at the top
        stack<int> stk;
        stk.push(-1);
        int maxarea = 0;
        for(int i = 0; i < heights.size(); ++i) {
            while(stk.top() != -1 && heights[stk.top()] > heights[i]) {
                int topIdx = stk.top();
                stk.pop();
                maxarea = max(maxarea, heights[topIdx] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int topIdx = stk.top();
            stk.pop();
            maxarea = max(maxarea, heights[topIdx] * ((int)heights.size() - stk.top() -1));
        }
        return maxarea;
    }

};
