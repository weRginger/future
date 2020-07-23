// Time O(logn) for all expect O(1) for top()
// Space O(n)
// Another more common approach is two stacks with time O(n) space O(n)
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        v.insert(v.begin(), x);
        m[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(it);
        return x;
    }

private:
    list<int> v;
    map<int, vector<list<int>::iterator>> m;
};
/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
