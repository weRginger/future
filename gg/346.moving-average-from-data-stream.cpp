class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }

    double next(int val) {
        if(q.size() == size) {
            sum = sum - q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum / (double) q.size();
    }
private:
    queue<int> q;
    double sum;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */