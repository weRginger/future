// Time O(1)
// Space O(n)
class AllOne {
public:
  /** Initialize your data structure here. */
  AllOne() {}
 
  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    auto it = m_.find(key);
    
    if (it == m_.end()) {
      if (l_.empty() || l_.front().value != 1) 
        l_.push_front({1, {key}});
      else
        l_.front().keys.insert(key);
      m_[key] = l_.begin();
      return;
    }
    
    auto lit = it->second;
    
    auto nit = next(lit);
    if (nit == l_.end() || nit->value != lit->value + 1)
      nit = l_.insert(nit, {lit->value + 1, {}});
    nit->keys.insert(key);
    m_[key] = nit;
    
    remove(lit, key);
  }
 
  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    auto it = m_.find(key);
    if (it == m_.end()) return;
    
    auto lit = it->second;
        
    if (lit->value > 1) {
      auto pit = prev(lit);
      if (lit == l_.begin() || pit->value != lit->value - 1)
        pit = l_.insert(lit, {lit->value - 1, {}});
      pit->keys.insert(key);
      m_[key] = pit;
    } else {
      // value == 1, remove from the data structure
      m_.erase(key);
    }
    
    remove(lit, key);    
  }
 
  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return l_.empty() ? "" : *l_.back().keys.cbegin();
  }
 
  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return l_.empty() ? "" : *l_.front().keys.cbegin();
  }
private:
  struct Node {  
    int value;
    unordered_set<string> keys;
  };
  
  list<Node> l_;
  unordered_map<string, list<Node>::iterator> m_;
  
  // Remove from old node.
  void remove(list<Node>::iterator it, const string& key) {
    it->keys.erase(key);
    if (it->keys.empty())
      l_.erase(it);
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
