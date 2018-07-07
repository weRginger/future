class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if (length == 0) return 0;
        int start = 0, end = length-1;
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (citations[mid] == length-mid) {
                return length-mid;
            } else if (citations[mid] > length-mid) {
                end = mid;
            } else {
                start = mid;
            }
        }
        // once jump out, always check start & end
        if (citations[start] >= length-start) return length-start;
        if (citations[end] >= length-end) return length-end;
        return 0;
    }
};