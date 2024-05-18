// Time O(1) per operation
// Space O(k)
class MyCircularQueue {
public:
  MyCircularQueue(int k): q_(k) {}
  
  bool enQueue(int value) {
    if (isFull()) return false;
    q_[(head_ + size_) % q_.size()] = value;    
    ++size_;
    return true;
  }
  
  bool deQueue() {
    if (isEmpty()) return false;
    head_ = (head_ + 1) % q_.size();
    --size_;
    return true;
  }
 
  int Front() { return isEmpty() ? -1 : q_[head_]; }
 
  int Rear() { return isEmpty() ? -1 : q_[(head_ + size_ - 1) % q_.size()]; }
 
  bool isEmpty() { return size_ == 0; }
 
  bool isFull() { return size_ == q_.size(); }
private:
  vector<int> q_;
  int head_ = 0;
  int size_ = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
