#include <iostream>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <functional>
using namespace std;

class ThreadSafeKVStore {
public:
    ThreadSafeKVStore(size_t num_buckets = 16) : num_buckets_(num_buckets), buckets_(num_buckets) {}

    void insert(const string& key, const string& value) {
        auto& bucket = get_bucket(key);
        unique_lock lock(bucket.mutex);
        bucket.map[key] = value;
    }

    string get(const string& key) {
        auto& bucket = get_bucket(key);
        shared_lock lock(bucket.mutex);
        auto it = bucket.map.find(key);
        if (it != bucket.map.end()) {
            return it->second;
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
        unordered_map<string, string> map;
        mutable shared_mutex mutex;
    };

    size_t num_buckets_;
    vector<Bucket> buckets_;

    Bucket& get_bucket(const string& key) {
        size_t hash = hash<string>{}(key);
        size_t bucket_index = hash % num_buckets_;
        return buckets_[bucket_index];
    }
};

// Test function for inserting key-value pairs
void insert_test(ThreadSafeKVStore& store, const string& key, const string& value) {
    store.insert(key, value);
    cout << "Inserted (" << key << ", " << value << ")\n";
}

// Test function for reading key-value pairs
void read_test(ThreadSafeKVStore& store, const string& key) {
    string value = store.get(key);
    if (!value.empty()) {
        cout << "Read (" << key << ", " << value << ")\n";
    } else {
        cout << "Key " << key << " not found\n";
    }
}

// Test function for removing key-value pairs
void remove_test(ThreadSafeKVStore& store, const string& key) {
    store.remove(key);
    cout << "Removed key " << key << "\n";
}

int main() {
    ThreadSafeKVStore store;

    vector<thread> threads;

    // Start some writer threads
    threads.emplace_back(insert_test, ref(store), "key1", "value1");
    threads.emplace_back(insert_test, ref(store), "key2", "value2");
    threads.emplace_back(insert_test, ref(store), "key3", "value3");

    // Start some reader threads
    threads.emplace_back(read_test, ref(store), "key1");
    threads.emplace_back(read_test, ref(store), "key2");
    threads.emplace_back(read_test, ref(store), "key4"); // key4 does not exist

    // Start some remover threads
    threads.emplace_back(remove_test, ref(store), "key2");
    threads.emplace_back(read_test, ref(store), "key2");

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
