// Time O(1)
// Space O(1)
class PeekingIterator : public Iterator {
    int pk;
    bool hn;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        hn = Iterator::hasNext();    
        pk = Iterator::next(); 
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return pk;  
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ans = pk;
        hn = Iterator::hasNext();    
        if(hn) pk = Iterator::next();
	    return ans;
	}
	
	bool hasNext() const {
	    return hn;
	}
};

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */
