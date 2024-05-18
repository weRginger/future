#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Interval {
    int from;
    int to;
    Interval(int f, int t) : from(f), to(t) {}
};

class Solution {
public:
    void addInterval(int from, int to) {
        v.push_back(Interval(from, to));
    }

    int getTotalCoveredLength() {
        sort(v.begin(), v.end(), [](Interval a, Interval b) {
            return a.from < b.from;
        });
        int ans = 0;
        Interval last = v[0];
        for(int i = 1; i < v.size(); i++) {
            if(v[i].from >= last.to) {
                ans += last.to - last.from;
                last = v[i];
            } else {
                last.to = max(last.to, v[i].to);
            }
        }
        ans += last.to - last.from;
        return ans;
    }

private:
    vector<Interval> v;
};

class Solution2 {
public:
    void addInterval(int from, int to) {
        for(int i = from; i < to; i++) {
            s.insert(i);
        }
    }

    int getTotalCoveredLength() {
        return s.size();
    }

private:
    unordered_set<int> s;
};

int main() {
    Solution2 s;
    s.addInterval(3, 6);
    s.addInterval(8, 9);
    s.addInterval(1, 5);
    //s.addInterval(1, 1);
    cout << s.getTotalCoveredLength() << endl;
    return 0;
}
