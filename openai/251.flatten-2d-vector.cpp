// author: ziqi
class Vector2D {
private:
    int x = 0;
    int y = 0;
    int n;
    vector<vector<int>> vec_;
public:
    Vector2D(vector<vector<int>>& vec) {
        vec_ = vec;
        n = vec_.size();
        for(int i = 0; i < n; i++) {
            auto& row = vec_[i];
            if(row.size()) {
                x = i;
                y = 0;
                return;
            }
        }
        x = n;
    }
    
    int next() {
        int ans = vec_[x][y];
        if(vec_[x].size() - 1 > y) {
            y++;
            return ans;
        }
        for(int i = x + 1; i < n; i++) {
            auto& row = vec_[i];
            if(row.size()) {
                x = i;
                y = 0;
                return ans;
            }
        }
        x = n;
        return ans;
    }
    
    bool hasNext() {
        return x != n;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
