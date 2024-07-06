#include <iostream>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <functional>
using namespace std;

class ThreadSafeVersionedKVStore {
public:
    ThreadSafeVersionedKVStore(size_t num_buckets = 16) : num_buckets_(num_buckets), buckets_(num_buckets) {}

    void insert(const string& key, const string& value, int timestamp) {
        auto& bucket = get_bucket(key);
        unique_lock lock(bucket.mutex);
        bucket.map[key].push_back({timestamp, value});
    }

    string get(const string& key, int timestamp) {
        auto& bucket = get_bucket(key);
        shared_lock lock(bucket.mutex);
        auto it = bucket.map.find(key);
        if (it == bucket.map.end()) {
            return "";
        }
        if (timestamp < bucket.map[key][0].first) {
            return "";
        }
        int l = 0, r = bucket.map[key].size() - 1;
        while(l + 1 < r) {
            int m = l + (r - l) / 2;
            if(timestamp <= bucket.map[key][m].first) {
                r = m;
            } else {
                l = m;
            }
        }
        if(bucket.map[key][r].first <= timestamp) {
            return bucket.map[key][r].second;
        } else if(bucket.map[key][l].first <= timestamp) {
            return bucket.map[key][l].second;
        }
        return "";
    }

    void remove(const string& key) {
        auto& bucket = get_bucket(key);
        unique_lock lock(bucket.mutex);
        bucket.map.erase(key);
    }

    bool exists(const string& key) {
        auto& bucket = get_bucket(key);
        shared_lock lock(bucket.mutex);
        return bucket.map.find(key) != bucket.map.end();
    }

private:
    struct Bucket {
        unordered_map<string, vector<pair<int,string>>> map;
        mutable shared_mutex mutex;
    };

    size_t num_buckets_;
    vector<Bucket> buckets_;

    Bucket& get_bucket(const string& key) {
        std::hash<std::string> hasher;
        size_t bucket_index = hasher(key) % num_buckets_;
        return buckets_[bucket_index];
    }
};

// Test function for inserting key-value pairs
void insert_test(ThreadSafeVersionedKVStore& store, const string& key, const string& value, int timestamp) {
    store.insert(key, value, timestamp);
    cout << "Inserted (" << key << " on time " << timestamp << ": " << value << ")\n";
}

// Test function for reading key-value pairs
void read_test(ThreadSafeVersionedKVStore& store, const string& key, int timestamp) {
    string value = store.get(key, timestamp);
    if (!value.empty()) {
        cout << "Read (" << key << " on time " << timestamp << ": " << value << ")\n";
    } else {
        cout << "Key " << key << " not found\n";
    }
}

int main() {
    ThreadSafeVersionedKVStore store;

    vector<thread> threads;

    // Start some writer threads
    threads.emplace_back(insert_test, ref(store), "key1", "value1", 1);
    threads.emplace_back(insert_test, ref(store), "key1", "value2", 5);
    threads.emplace_back(insert_test, ref(store), "key2", "value3", 10);
    threads.emplace_back(insert_test, ref(store), "key1", "value1", 10);

    // Start some reader threads
    threads.emplace_back(read_test, ref(store), "key1", 6);
    threads.emplace_back(read_test, ref(store), "key2", 1);
    threads.emplace_back(read_test, ref(store), "key2", 10);
    threads.emplace_back(read_test, ref(store), "key1", 10);
    threads.emplace_back(read_test, ref(store), "key4", 1); // key4 does not exist

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
