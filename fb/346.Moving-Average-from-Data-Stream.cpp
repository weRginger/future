// Time O(1) per next()
// Space O(window size)
class MovingAverage {
    double sum;
    int len;
    queue<int>q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0, len = size;
    }
    
    double next(int val) {
        if (q.size() < len) {
            q.push(val);
            sum += val;
            return sum/q.size();
        }
        
        sum += (val - q.front());
        q.pop();
        q.push(val);
        return sum/len;
    }
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
