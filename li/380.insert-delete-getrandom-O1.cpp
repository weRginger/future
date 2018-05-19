class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};

// By Ziqi
class RandomizedSet {
private:
    unordered_map<int, int> index;
    unordered_map<int, int> reverseIndex;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!reverseIndex.count(val)) {
            reverseIndex[val] = index.size();
            index[index.size()] = val;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(reverseIndex.count(val)) {
            int idx = reverseIndex[val];
            int lastVal;
            if(index.size() > 1) {
                lastVal = index[index.size() - 1];
                index[idx] = lastVal;
                reverseIndex[lastVal] = idx;
            }
            reverseIndex.erase(val);
            index.erase(index.size() - 1);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int num = random() % index.size();
        return index[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
