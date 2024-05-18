#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    static int mergeFiles(const vector<int>& files) {
        int resSum = 0;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int file : files) {
            minHeap.push(file);
        }
        while (minHeap.size() != 1) {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            int tmpSum = first + second;
            resSum += tmpSum;
            minHeap.push(tmpSum);
        }
        return resSum;
    }
};

int main() {
    int ret = Solution::mergeFiles(vector<int>{{8, 4, 6, 12}});
    assert(58 == ret);
    ret = Solution::mergeFiles(vector<int>{{8, 3, 5, 2, 15}});
    assert(66 == ret);
    return 0;
}
