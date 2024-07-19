class HitCounter {
private:
    int past_sec = 300;
    queue<int> q_;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q_.push(timestamp);
    }
    
    int getHits(int timestamp) {
        if(timestamp <= past_sec) {
            return q_.size();
        }
        while(!q_.empty()) {
            int front = q_.front();
            if(front <= timestamp - past_sec) {
                q_.pop();
            } else {
                return q_.size();
            }
        }
        return 0;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
