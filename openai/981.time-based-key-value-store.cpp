// Time O(logn) per get; O(1) per set
// Space O(n)
// author: ziqi
class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> time_map;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!time_map.count(key)) {
            return "";
        }
        if (timestamp < time_map[key][0].first) {
            return "";
        }
        int l = 0, r = time_map[key].size() - 1;
        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(timestamp <= time_map[key][m].first) {
                r = m;
            } else {
                l = m;
            }
        }
        if(time_map[key][r].first <= timestamp) {
            return time_map[key][r].second;
        } else if(time_map[key][l].first <= timestamp) {
            return time_map[key][l].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
