#include <iostream>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <functional>

class ThreadSafeKVStore {
public:
    ThreadSafeKVStore(size_t num_buckets = 16) : num_buckets_(num_buckets), buckets_(num_buckets) {}

    void insert(const std::string& key, const std::string& value) {
        auto& bucket = get_bucket(key);
        std::unique_lock lock(bucket.mutex);
        bucket.map[key] = value;
    }

    std::string get(const std::string& key) {
        auto& bucket = get_bucket(key);
        std::shared_lock lock(bucket.mutex);
        auto it = bucket.map.find(key);
        if (it != bucket.map.end()) {
            return it->second;
        }
        return "";
    }

    void remove(const std::string& key) {
        auto& bucket = get_bucket(key);
        std::unique_lock lock(bucket.mutex);
        bucket.map.erase(key);
    }

    bool exists(const std::string& key) {
        auto& bucket = get_bucket(key);
        std::shared_lock lock(bucket.mutex);
        return bucket.map.find(key) != bucket.map.end();
    }

private:
    struct Bucket {
        std::unordered_map<std::string, std::string> map;
        mutable std::shared_mutex mutex;
    };

    size_t num_buckets_;
    std::vector<Bucket> buckets_;

    Bucket& get_bucket(const std::string& key) {
        size_t hash = std::hash<std::string>{}(key);
        size_t bucket_index = hash % num_buckets_;
        return buckets_[bucket_index];
    }
};

// Test function for inserting key-value pairs
void insert_test(ThreadSafeKVStore& store, const std::string& key, const std::string& value) {
    store.insert(key, value);
    std::cout << "Inserted (" << key << ", " << value << ")\n";
}

// Test function for reading key-value pairs
void read_test(ThreadSafeKVStore& store, const std::string& key) {
    std::string value = store.get(key);
    if (!value.empty()) {
        std::cout << "Read (" << key << ", " << value << ")\n";
    } else {
        std::cout << "Key " << key << " not found\n";
    }
}

// Test function for removing key-value pairs
void remove_test(ThreadSafeKVStore& store, const std::string& key) {
    store.remove(key);
    std::cout << "Removed key " << key << "\n";
}

int main() {
    ThreadSafeKVStore store;

    std::vector<std::thread> threads;

    // Start some writer threads
    threads.emplace_back(insert_test, std::ref(store), "key1", "value1");
    threads.emplace_back(insert_test, std::ref(store), "key2", "value2");
    threads.emplace_back(insert_test, std::ref(store), "key3", "value3");

    // Start some reader threads
    threads.emplace_back(read_test, std::ref(store), "key1");
    threads.emplace_back(read_test, std::ref(store), "key2");
    threads.emplace_back(read_test, std::ref(store), "key4"); // key4 does not exist

    // Start some remover threads
    threads.emplace_back(remove_test, std::ref(store), "key2");
    threads.emplace_back(read_test, std::ref(store), "key2");

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
