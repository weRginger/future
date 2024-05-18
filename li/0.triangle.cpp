#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getTriangleSides(vector<int>& input) {
        if(input.empty() || input.size() < 3) return vector<int> {};
        sort(input.begin(), input.end());
        for(int i = 0; i < input.size() - 2; i++) {
            if(isTriangle(input[i], input[i+1], input[i+2])) {
                return vector<int> {input[i], input[i+1], input[i+2]};
            }
        }
        return vector<int> {};
    }

private:
    bool isTriangle(int a, int b, int c) {
        return a + b > c && a + c > b && b + c > a;
    }
};

int main() {
    Solution s;
    vector<int> input = {1,10,4,7,2};
    vector<int> ret = s.getTriangleSides(input);
    for(auto i : ret) {
        cout << i << " ";
    }
    cout << endl;

    input = {};
    ret = s.getTriangleSides(input);
    for(auto i : ret) {
        cout << i << " ";
    }
    cout << endl;

    input = {1,6,2,44,101};
    ret = s.getTriangleSides(input);
    for(auto i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}