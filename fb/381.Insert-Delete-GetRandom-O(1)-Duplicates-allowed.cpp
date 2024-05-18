// Time O(N), where N is num of operations
// Space O(N)
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        val_idx[val].insert(vi.size());
        vi.push_back(val);
        return val_idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (val_idx.count(val) == 0 || val_idx[val].size() == 0) return false;
        int idx = *(val_idx[val].begin());
        val_idx[val].erase(idx);
        if (vi.size() > 1 && idx != vi.size() - 1) {
            int last_val = vi.back();
            vi[idx] = last_val;
            val_idx[last_val].erase(vi.size() - 1);
            val_idx[last_val].insert(idx);
        }
        vi.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vi[rand() % vi.size()];
    }

private:
    vector<int> vi;
    unordered_map<int, unordered_set<int>> val_idx;
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
