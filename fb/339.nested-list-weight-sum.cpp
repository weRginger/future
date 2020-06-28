// Time O(n)
// Space O(k) - k is max depth
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int ans = 0;
        for(auto i : nestedList) {
            helper(i, 1, ans);
        }
        return ans;
    }
    
private:
    int helper(const NestedInteger& ni, int d, int& ans) {
        if(ni.isInteger()) {
            ans += ni.getInteger() * d;
        } else {
            for(auto i : ni.getList()) {
                helper(i, d + 1, ans);
            }
        }
        return ans;
    }
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
