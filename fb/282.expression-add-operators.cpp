class Solution {
public:

    void addOperators(string num,int target,string curr,int sum,int last,vector<string> &res) {
        if(num.empty()) {
            if(target == sum) {
                res.push_back(curr);
            }
            return;
        }

        for(int i = 0; i < num.size(); ++i) {
            string sub = num.substr(0,i + 1);

            if(sub.size() > 1 && sub[0] == '0') {
                continue;
            }

            istringstream ss(sub);
            int n = 0;
            ss >> n;

            if(curr.empty()) {
                addOperators(num.substr(i + 1),target,sub,n,n,res);
            }
            else {
                addOperators(num.substr(i + 1),target,curr +  "+" + sub,sum + n,n,res);
                addOperators(num.substr(i + 1),target,curr +  "-" + sub,sum - n,-n,res);
                addOperators(num.substr(i + 1),target,curr +  "*" + sub,(sum - last) + last*n ,last*n,res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperators(num,target,"",0,0,res);
        return res;
    }
};