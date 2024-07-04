// Time O(logn) per get; O(1) per set
// Space O(n)
// author: ziqi. time limit exceed, even it is the same as LC answer
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
        auto v = time_map[key];
        int l = 0, r = v.size() - 1;
        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(timestamp <= v[m].first) {
                r = m;
            } else {
                l = m;
            }
        }
        if(v[r].first <= timestamp) {
            return v[r].second;
        } else if(v[l].first <= timestamp) {
            return v[l].second;
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
