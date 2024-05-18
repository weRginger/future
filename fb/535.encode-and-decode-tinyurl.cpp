class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getRand();
        while (mp.count(key)) {
            key = getRand();
        }
        mp[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string pattern = "http://tinyurl.com/";
        string key = shortUrl.replace(shortUrl.find(pattern), pattern.size(), "");
        return mp[key];
    }

private:
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> mp;
    default_random_engine generator;
    uniform_int_distribution<int> distribution = uniform_int_distribution<int>(0,61);

    string getRand() {
        string s;
        for (int i = 0; i < 6; i++) {
            s += alphabet[distribution(generator)];
        }
        return s;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));