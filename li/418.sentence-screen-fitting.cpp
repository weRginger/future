class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> dp(sentence.size(), 0);
        int n = sentence.size();
        
        // Construct DP
        // dp[i] denotes how many words we have used to fill 
        // the row of having word sentence[i] as the leading word
        for(int i = 0, prev = 0, len = 0; i < sentence.size(); ++i) {
            // remove the length of previous word and space
            if(i != 0 && len > 0) len -= sentence[i - 1].size() + 1;
            // calculate the start of next line.
            // it's OK the index is beyond the length of array so that
            // we can use it to count how many words one row has.
            while(len + sentence[prev % n].size() <= cols) len += sentence[prev++ % n].size() + 1;
            dp[i] = prev;
        }
        int count = 0;
        for(int i = 0, k = 0; i < rows; ++i) {
            // count how many words one row has and move to start of next row.
            // It's better to check if d[k] == k but I find there is no test case on it.
            // if(dp[k] == k) return 0;
            count += dp[k] - k;
            k = dp[k] % n;
        }
        // divide by the number of words in sentence
        return count / n;
    }
};
