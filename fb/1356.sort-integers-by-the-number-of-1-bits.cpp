// Time O(nlogn)
// Space O(n)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [](const int& a, const int& b) {
            int a_count = 0;
            int b_count = 0;
            int tmp_a = a;
            int tmp_b = b;
            while(tmp_a) {
                if(tmp_a & 1) a_count ++;
                tmp_a = tmp_a >> 1;
            }
            while(tmp_b) {
                if(tmp_b & 1) b_count ++;
                tmp_b = tmp_b >> 1;
            }
            if(a_count == b_count) {
                return a < b;
            }
            return a_count < b_count;
        };
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
