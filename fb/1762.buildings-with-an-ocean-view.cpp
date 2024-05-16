// Time O(n)
// Space O(1)
class Solution {
private:
    void reverse(vector<int>& inputs) {
        for(int i = 0, j = inputs.size() - 1; i < j; i++, j--) {
            int tmp = inputs[i];
            inputs[i] = inputs[j];
            inputs[j] = tmp;
        }
    }
public:
    vector<int> findBuildings(vector<int>& heights) {
        int sz = heights.size();
        int mx = 0;
        vector<int> ans;
        for(int i = sz - 1; i > -1; i--) {
            if(heights[i] > mx) {
                ans.push_back(i);
                mx = heights[i];
            }
        }
        reverse(ans);
        return ans;
    }
};
