// Time O(NlogN)
// Space O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Sort in ascending order of attack, 
        // If attack is same sort in descending order of defense
        auto comp = [](const vector<int>& a, vector<int>& b) {
            return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
        };
        sort(properties.begin(), properties.end(), comp);
             
        int weakCharacters = 0;
        int maxDefense = 0;
        for (int i = (int)properties.size() - 1; i >= 0; i--) {
            // Compare the current defense with the maximum achieved so far
            if (properties[i][1] < maxDefense) {
                weakCharacters++;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        
        return weakCharacters;
    }
};
