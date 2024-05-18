class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.empty()) return true;
        int five = 0, ten = 0;
        for(auto b : bills) {
            switch (b) {
                case 5:
                    five++;
                    break;
                case 10:
                    if(five == 0) return false;
                    five--;
                    ten++;
                    break;
                default: // 20 bills
                    if(five > 0 && ten > 0) {
                        five--;
                        ten--;
                    } else if(five > 2) {
                        five -= 3;
                    } else {
                        return false;
                    }
            }
            
        }
        return true;
    }
};
