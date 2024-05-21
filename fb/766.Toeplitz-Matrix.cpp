// Time O(mn)
// Space O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int r = 0; r < matrix.size(); ++r)
            for (int c = 0; c < matrix[0].size(); ++c)
                if (r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c])
                    return false;
        return true;
    }
};

/*
Follow up questions in LC:
1. What if the matrix is stored on disk, and the memory is limited such that you can 
only load at most one row of the matrix into the memory at once?
2. What if the matrix is so large that you can only load up a partial row into the memory 
at once?

A1: Load the first row. Shift the row one spot to the right. Fill the new empty spot on the
left with the first element from the second row. Compare the remaining elements of the second
row with the existing elements of the shifted row. Keep shifting, filling and comparing until
you've done all rows. Don't actually do the shifting but simulate it by keeping track of an offset.
A1 Ziqi's takeaway: since the rightmost element in each row could be discarded

A2: Pick a number of columns that fits in memory. Do the above process for only the first n columns.
Then repeat for the next n columns etc. until done. Make sure there is 1 column overlap to guarantee
the diagonals match between shards.
*/
