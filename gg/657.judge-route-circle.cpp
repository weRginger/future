class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.empty()) return false;
        int x = 0;
        int y = 0;
        for(auto c : moves) {
            if(c == 'R')        x++;
            else if(c == 'L')   x--;
            else if(c == 'U')   y++;
            else                y--;
        }
        if(x == 0 && y == 0) return true;
        return false;
    }
};