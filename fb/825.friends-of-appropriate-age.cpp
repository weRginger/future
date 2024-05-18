// Time O(A^2+N), where N is the number of people, and A is the number of ages
// Space O(A)
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (auto age: ages)
            count[age]++;
        
        int ans = 0;
        for(int x = 1; x <= 120; x++){
            int n1 = count[x];
            for(int y = 1; y <= 120; y++){
                int n2 = count[y];
                if(!(y <= (0.5 * x + 7) || y > x || ( y > 100 && x < 100))){
                    ans += n1*n2;
                    if(x==y){
                        ans -= n1;
                    }
                }
            }
        }

        return ans;
    }
};
