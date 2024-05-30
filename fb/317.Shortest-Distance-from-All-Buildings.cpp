/*
https://www.cnblogs.com/grandyang/p/5297683.html
这道题给我们了一些建筑物的坐标和一些障碍物的坐标，让我们找一个位置，使其到所有建筑物的曼哈顿距离之和最小，
起初我觉得这题应该算Best Meeting Point那道题的拓展，不同之处在于这道题有了障碍物的存在，这样就使得直接使
用曼哈顿距离的计算公式变得不可行，因为在有些情况下，障碍物完全封死了某个建筑物，那么这时候应该返回-1。所以
这道题只能使用遍历迷宫的思想来解，那么这题就和之前那道Walls and Gates很类似，但是这道题用DFS就会很麻烦，
因为我们的目标是要建立Distance Map，所以BFS的特性使得其非常适合建立距离场，而DFS由于是沿着一个方向一股脑
的搜索，然后会面临着更新距离的问题，只有当递归函数都调用结束后，距离场才建立好，那么我们累加距离场时又得整
个遍历一遍，非常不高效。主要原因还是由于DFS的搜索方式不适合距离场，因为BFS遍历完一个点后，不会再来更改这个
点的值，而DFS会反复的更改同一个点的值，我强行用DFS写出的方法无法通过OJ最后一个大集合，所以这道题还是老老实
实地用BFS来解题吧，还是需要借助queue来遍历，我们对于每一个建筑的位置都进行一次全图的BFS遍历，每次都建立一
个dist的距离场，由于我们BFS遍历需要标记应经访问过的位置，而我们并不想建立一个visit的二维矩阵，那么怎么办呢，
这里用一个小trick，我们第一遍历的时候，都是找0的位置，遍历完后，我们将其赋为-1，这样下一轮遍历我们就找-1的
位置，然后将其都赋为-2，以此类推直至遍历完所有的建筑物，然后在遍历的过程中更新dist和sum的值，注意我们的dist
算是个局部变量，每次都初始化为grid，真正的距离场累加在sum中，由于建筑的位置在grid中是1，所以dist中初始化也
是1，累加到sum中就需要减1，我们用sum中的值来更新结果res的值，最后根据res的值看是否要返回-1
*/
// Time O(m^2*n^2)
// Space O(mn)
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX; // need to set res back to INT_MAX
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int a = q.front().first, b = q.front().second; q.pop();
                        for (int k = 0; k < dirs.size(); ++k) {
                            int x = a + dirs[k][0], y = b + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                --grid[x][y];
                                dist[x][y] = dist[a][b] + 1;
                                sum[x][y] += dist[x][y] - 1;//-1 since each building value is 1
                                q.push({x, y});
                                res = min(res, sum[x][y]);
                            }
                        }
                    }
                    --val;                    
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
