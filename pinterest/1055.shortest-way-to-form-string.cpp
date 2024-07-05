// Time complexity: O(S+Tlog(S)), where S is the length of source and T is the length of target.
// Space complexity: O(S).
// LC answer
// LC has O(S+T), but won't want to learn how
class Solution {
public: 
    int shortestWay(string source, string target) {

        // Array to store the vector of charToIndices of each character in source
        vector < int > charToIndices[26];
        for (int i = 0; i < source.size(); i++) {
            charToIndices[source[i] - 'a'].push_back(i);
        }

        // The current index in source
        int sourceIterator = 0;

        // Number of times we have to iterate through source to get target
        int count = 1;

        // Find all characters of target in source
        for (int i = 0; i < target.size(); i++) {

            // If the character is not present in source, return -1
            if (charToIndices[target[i] - 'a'].size() == 0) {
                return -1;
            }

            // Binary search to find the index of the character in source next to the source iterator
            vector < int > indices = charToIndices[target[i] - 'a'];
            int index = lower_bound(indices.begin(), indices.end(), sourceIterator) - indices.begin();

            // If we have reached the end of the list, we need to iterate
            // through source again, hence first index of character in source.
            if (index == indices.size()) {
                count++;
                sourceIterator = indices[0] + 1; // use indices[0] for target[i], so advance sourceIterator with +1
            } else {
                sourceIterator = indices[index] + 1;
            }
        }

        return count;
    }
};
