/*
It doesn't matter how many steps are taken, the scores will cancel out and only 1st and last matter.
[i.e. c2-c1 + c3-c2 + c4-c3 + c5-c4 = c5-c1]

So we need to find 2 points with max difference (with bottom-right point larger).
Start from (m-1,n-1) and use 2D DP to store max element encountered so far.

If it helps you understand, please upvote!
*/
// time O(m*n)
// space O(m*n)
class Solution {
public:
    int maxScore(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        dp[m-1][n-1]=a[m-1][n-1];
        int ans=INT_MIN;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int right_max = INT_MIN;
                int down_max = INT_MIN;
                if(i==m-1){
                    right_max = dp[i][j+1];
                }
                else if(j==n-1){
                    down_max = dp[i+1][j];
                }
                else{
                    right_max = dp[i][j+1];
                    down_max = dp[i+1][j];
                }
                ans = max(ans, max(right_max, down_max)-a[i][j]);
                dp[i][j]=max(a[i][j],max(right_max, down_max));
            }
        }
        return ans;
    }
    int dp[1000][1000];
};
