// Time O(n)
// Space O(n)
// using stack to keep a sorted array that the current person is the shortest,
// since the current one can only see the ones are taller than itself to the right
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        vector<int>ans(heights.size());
        if(heights.size()==1) return ans;
          for(int i = heights.size()-1 ;i > =0 ;i--){
            int c = 1; // default as there would be one person in the right side higher than current one
            while(!st.empty() && heights[i] >= st.top()){
                c++; // count how many are shorter than current one till the one taller than it to the right
                st.pop();
            }
            if(st.empty()) c--; // minus 1 since the current person is the highest of all to the right
            ans[i] = c;
            st.push(heights[i]);
        }
        return ans;
    }
};
