// Time O(1) for both hit, gitHits (amortized) and ctor
// Space O(n)
// this is the optimmized solution for LC follow up q: What if the number of hits per second could be huge? Does your design scale?
class HitCounter {
private:
    int past_sec = 300;
    int total;
    queue<pair<int, int>> q_; // pair.first is the ts, second is the count for this ts
public:
    HitCounter() {
        total = 0;
    }
    
    void hit(int timestamp) {
        if(q_.empty() || q_.back().first != timestamp) {
            q_.push({timestamp, 1});
        } else {
            q_.back().second++;
        }
        total++;
    }
    
    int getHits(int timestamp) {
        if(timestamp <= past_sec) {
            return total;
        }
        while(!q_.empty()) {
            auto front = q_.front();
            if(front.first <= timestamp - past_sec) {
                q_.pop();
                total -= front.second;
            } else {
                return total;
            }
        }
        return 0;
    }
};

// Time O(1) for both hit, gitHits (amortized) and ctor
// Space O(n)
// no optimized for follow up q
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
