/*
meta phone screen qs

There are 2 arrays which denote departing and returning flights with the respective indexes being time and the values
of the array being the cost it takes for the flight. Return the minimum cost for a round trip provided the return flight 
can only be taken at a time post departing flight time (i.e if departing at time i, one can catch a returning flight only 
from time (i+1) onwards). 

For eg departing = [1,2,3,4] and returning = [4,3,2,1], the minimum cost for round trip will be 2 i.e departing[0] + returning[3].

Solve this is O(n) time
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int findMinCost(vector<int>& departing, vector<int>& returning) {
        int minDepartCost = INT_MAX;
        int minTotalCost = INT_MAX;
        for(int i = 0; i < departing.size() - 1; i++) {
            minDepartCost = min(minDepartCost, departing[i]);
            minTotalCost = min(minTotalCost, returning[i+1] + minDepartCost);
        }
        return minTotalCost;
    }
};

int main()
{
    vector<int> departing = {1, 2, 3, 4};
    vector<int> returning = {4, 3, 2, 1};
    Solution s = Solution();
    cout << s.findMinCost(departing, returning) << endl;
    return 0;
}
