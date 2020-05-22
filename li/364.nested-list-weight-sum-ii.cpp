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

// O(1) space
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getMaxDepth(nestedList);
        sum = 0;
        getSum(nestedList, depth);
        return sum;
    }
private:
    int sum;
    
    int getMaxDepth(vector<NestedInteger>& nestedList){
        int depth = 1;
        for(int i = 0; i < nestedList.size(); i++){
            if(!nestedList[i].isInteger())
                depth = max(depth, 1 + getMaxDepth(nestedList[i].getList()));
        }
        return depth;
    }
    
    void getSum(vector<NestedInteger>& nestedList, int depth){
        for(int i = 0; i < nestedList.size(); i++){
            if(!nestedList[i].isInteger())
                getSum(nestedList[i].getList(), depth-1);
            else
                sum +=nestedList[i].getInteger() * depth;
        }
    }
};

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if(nestedList.empty()) {
            return 0;
        }
        vector<int> sum;
        for(int i = 0; i < nestedList.size(); i++) {
            helper(nestedList[i], 0, sum);
        }
        int ans = 0;
        for(int i = 0, j = sum.size(); i < sum.size(); i++, j--) {
            ans += sum[i] * j;
        }
        return ans;
    }
    void helper(NestedInteger n, int level, vector<int>& sum) {
        if(sum.size() < level + 1) {
            sum.resize(level + 1);
        }
        if(n.isInteger()) {
            sum[level] += n.getInteger();
        }
        else {
            vector<NestedInteger> v = n.getList();
            for(int i = 0; i < v.size(); i++) {
                helper(v[i], level + 1, sum);
            }
        }
    }
};
