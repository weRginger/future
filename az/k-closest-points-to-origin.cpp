// Note: must use a struct to represent each point in case there are points with the same values
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int x;
    int y;
    int dist;
    Node(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

class FindKClosest{
public:
    static vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
        vector<vector<int>> res;
        auto comp = [](Node& a, Node& b) {
            return a.dist < b.dist;
        };
        priority_queue<Node, vector<Node>, decltype(comp)> heap(comp);
        for (auto &point : points) {
            int dist = pow(point[0], 2) + pow(point[1], 2);
            if (heap.size() < K) {
                heap.push(Node(point[0], point[1], dist));
            } else if (dist < heap.top().dist) {
                heap.pop();
                heap.push(Node(point[0], point[1], dist));
            }
        }
        while (!heap.empty()) {
            Node node = heap.top();
            heap.pop();
            res.push_back(vector<int>{node.x, node.y});
        }
        return res;
    }
};
