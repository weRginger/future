// Time O(N∗log(max−min))
// Space O(1)
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int start = matrix[0][0], end = matrix[n - 1][n - 1];
    while (start < end) {
      int mid = start + (end - start) / 2;
      // first number is the smallest and the second number is the largest
      pair<int, int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};
      int count = countLessEqual(matrix, mid, smallLargePair);
      if (count == k) {
        return smallLargePair.first;
      }

      if (count < k) {
        start = smallLargePair.second;  // search higher
      } else {
        end = smallLargePair.first;  // search lower
      }
    }

    return start;
  }

private:
  int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair) {
    int count = 0;
    int n = matrix.size(), row = n - 1, col = 0;
    while (row >= 0 && col < n) {
      if (matrix[row][col] > mid) {
        // as matrix[row][col] is bigger than the mid, let's keep track of the
        // smallest number greater than the mid
        smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
        row--;
      } else {
        // as matrix[row][col] is less than or equal to the mid, let's keep track of the
        // biggest number less than or equal to the mid
        smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
        count += row + 1;
        col++;
      }
    }
    return count;
  }
};

// Time: O(X + K*log(X)), where X is min(K,N)
// Space: O(X)
class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        auto comp = [](const pair<int, pair<int, int>> &x, 
                       const pair<int, pair<int, int>> &y) {
            return x.first > y.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> minHeap(comp);

        // put the 1st element of each row in the min heap
        // we don't need to push more than 'k' elements in the heap
        for (int i = 0; i < n && i < k; i++) {
          minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }

        // take the smallest element form the min heap, if the running count is equal to k return the number
        // if the row of the top element has more elements, add the next element to the heap
        int numberCount = 0, result = 0;
        while (!minHeap.empty()) {
          auto heapTop = minHeap.top();
          minHeap.pop();
          result = heapTop.first;
          if (++numberCount == k) {
            break;
          }

          heapTop.second.second++;
          if (heapTop.second.second < n ) {
            heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
            minHeap.push(heapTop);
          }
        }
        return result;
    }
};
