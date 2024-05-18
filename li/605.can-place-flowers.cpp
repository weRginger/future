class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        if(flowerbed.empty()) return false;
        int s = flowerbed.size();
        for(int i = 0; i < s; i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == s - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
            if(n == 0) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int s = flowerbed.size();
        for(int i = 0; i < s; i++) {
            int pre = i == 0 ? 0 : flowerbed[i-1];
            int next = i == s - 1 ? 0 : flowerbed[i+1]; 
            if(flowerbed[i] == 0 && pre == 0 && next == 0) {
                flowerbed[i] = 1;
                n--;
                if(n == 0) return true;
            }
        }
        return false;    
    }
};
