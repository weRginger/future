// Time O(1) per op
// Space O(n)
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(um.count(message)) {
            if(timestamp - um[message] < 10)
                return false;
            else {
                um[message] = timestamp;
                return true;
            }
        }
        um[message] = timestamp;
        return true;
    }

private:
    unordered_map<string, int> um;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
