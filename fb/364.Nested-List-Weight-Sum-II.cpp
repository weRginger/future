// Time O(N), where N is total num of integers
// Space O(H), where H is max level
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        getMaxDepth(nestedList, 1);
        getDepthSum(nestedList, maxDepth);
        return ans;
    }
private:
    int ans = 0;
    int maxDepth = 1;
    void getMaxDepth(vector<NestedInteger>& nestedList, int depth) {
        maxDepth = max(maxDepth, depth);
        for(auto i : nestedList) {
            if(!i.isInteger()) {
                getMaxDepth(i.getList(), depth+1);
            }
        }
    }
    
    void getDepthSum(vector<NestedInteger>& nestedList, int weight) {
        for(auto i : nestedList) {
            if(!i.isInteger()) {
                getDepthSum(i.getList(), weight-1);
            } else {
                ans += i.getInteger() * weight;
            }
        }
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
