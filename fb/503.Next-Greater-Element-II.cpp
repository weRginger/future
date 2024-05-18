/*
我们遍历两倍的数组，然后还是坐标i对n取余，取出数字，如果此时栈不为空，且栈顶元素
小于当前数字，说明当前数字就是栈顶元素的右边第一个较大数，那么建立二者的映射，并
且去除当前栈顶元素，最后如果i小于n，则把i压入栈。因为res的长度必须是n，超过n的部
分我们只是为了给之前栈中的数字找较大值，所以不能压入栈
https://www.cnblogs.com/grandyang/p/6442861.html
*/
// Time O(n)
// Space O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num; st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};
