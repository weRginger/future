// Time O(logn + k)
// Space O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos=lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        
        if(pos-1 >= 0 && (x - arr[pos-1] <= arr[pos] - x))
            pos--;
        
        int left = pos - 1;
        int right = pos + 1;
        int n = arr.size();
        while(right - left - 1 < k) {
            if(left >= 0 && (right == n || x-arr[left] <= arr[right]-x)) 
                left--;
            else 
                right++;
        }
        return vector<int>(arr.begin()+left+1,arr.begin()+right);
    }
};
