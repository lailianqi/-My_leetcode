#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//这题写不出来 这题DFS的解法 显然不可行

// 直接看的答案 来自LeetCode的答案
// https://leetcode.com/problems/cut-off-trees-for-golf-event/discuss/107404/Java-solution-PriorityQueue-+-BFS
// https://leetcode.com/problems/cut-off-trees-for-golf-event/discuss/107403/C++-Sort-+-BFS-with-explanation
class Solution {
  private:
    class threeTuple {
      public:
        int i;
        int j;
        int val;
        threeTuple(int i, int j, int val) {
            this->i = i;
            this->j = j;
            this->val = val;
        }
    };
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int cutOffTree(vector<vector<int>> &forest) {
        int m = forest.size(), n = forest[0].size(), sum = 0;
        auto comp = [](threeTuple &a, threeTuple &b) { return a.val > b.val; };
        priority_queue<threeTuple, vector<threeTuple>, decltype(comp)> pq(comp);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    pq.push(threeTuple(i, j, forest[i][j]));
                }
            }
        }
        vector<int> start = {0, 0};
        while (!pq.empty()) {
            threeTuple t = pq.top();
            pq.pop();
            int step = minStep(forest, start, t);
            if (step < 0) {
                return -1;
            }
            sum += step;
            start[0] = t.i;
            start[1] = t.j;
        }
        return sum;
    }
    int minStep(vector<vector<int>> &forest, vector<int> start,
                threeTuple &target) {
        int m = forest.size(), n = forest[0].size(), step = 0;
        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> curr = q.front();
                q.pop();
                if (curr[0] == target.i && curr[1] == target.j)
                    return step;
                for (vector<int> d : dir) {
                    int nr = curr[0] + d[0];
                    int nc = curr[1] + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        forest[nr][nc] == 0 || visited[nr][nc])
                        continue;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            step++;
        }
        return -1;
    }
};

// 官方的题解 写的非常的好
// https://leetcode.com/articles/cutoff-trees-for-golf-event/
// 有对A*算法的描述

/*************************************/

class Solution_00 {
  private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int cutOffTree(vector<vector<int>> &forest) {
        vector<vector<int>> trees;
        int m = forest.size(), n = forest[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(trees.begin(), trees.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        int ans = 0, sr = 0, sc = 0;
        for (vector<int> tree : trees) {
            int d = cutOffTree(forest, sr, sc, tree[1], tree[2]);
            if (d < 0)
                return -1;
            ans += d;
            sr = tree[1];
            sc = tree[2];
        }
        return ans;
    }
    int cutOffTree(vector<vector<int>> &forest, int sr, int sc, int tr,
                   int tc) {
        int R = forest.size(), C = forest[0].size();
        auto comp = [](vector<int> &a, vector<int> &b) { return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(
            comp);
        pq.push({0, 0, sr, sc});
        unordered_map<int, int> costDir;
        costDir[sr * C + sc] = 0;
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            int g = cur[1], r = cur[2], c = cur[3];
            if (r == tr && c == tc)
                return g;
            for (vector<int> d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if (0 <= nr && nr < R && 0 <= nc && nc < C &&
                    forest[nr][nc] > 0) {
                    int ncost = g + 1 + abs(nr - tr) + abs(nc - tc);
                    if (costDir.count(nr * C + nc) == 0 ||
                        ncost < costDir[nr * C + nc]) {
                        costDir[nr * C + nc] = ncost;
                        pq.push({ncost, g + 1, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

// 第二种写法 上面的改进版
// https://leetcode.com/problems/cut-off-trees-for-golf-event/discuss/107427/C++-BFS-with-optimization-86ms-beats-100

class Solution_0 {
  public:
    int cutOffTree(vector<vector<int>> &forest) {
        vector<vector<int>> trees; // vector<[height,i,j]>
        for (int i = 0; i < forest.size(); ++i)
            for (int j = 0; j < forest[0].size(); ++j)
                if (forest[i][j] > 1)
                    trees.push_back(vector<int>({forest[i][j], i, j}));
        sort(trees.begin(), trees.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0]; // sort by tree's height
        });

        // doing DFS to see if every tree is available from (0,0)
        int tree_available = 0;
        vector<vector<bool>> visited(forest.size(),
                                     vector<bool>(forest[0].size(), false));
        DFS(0, 0, visited, forest, tree_available);
        if (tree_available != trees.size())
            return -1; // some trees are not available from (0,0)

        int step = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < trees.size(); ++i) {
            // optimization here, if there are no obstacles blocking the
            // shortest path, return the shortest length no need to do the
            // 4-direction BFS
            if (ShortestPathAvailable(si, sj, trees[i][1], trees[i][2], forest))
                step += abs(si - trees[i][1]) + abs(sj - trees[i][2]);
            else
                step += BFS(si, sj, trees[i][1], trees[i][2], forest);
            si = trees[i][1];
            sj = trees[i][2];
        }

        return step;
    }

    void DFS(int i, int j, vector<vector<bool>> &visited,
             const vector<vector<int>> &forest, int &count) {
        if (i < 0 || i >= forest.size() || j < 0 || j >= forest[0].size() ||
            visited[i][j] || forest[i][j] == 0)
            return;
        visited[i][j] = true;
        if (forest[i][j] > 1)
            count++;
        DFS(i + 1, j, visited, forest, count);
        DFS(i - 1, j, visited, forest, count);
        DFS(i, j + 1, visited, forest, count);
        DFS(i, j - 1, visited, forest, count);
    }

    // return the minimum step from (si,sj) to (ti,tj)
    int BFS(int si, int sj, int ti, int tj, const vector<vector<int>> &forest) {
        vector<vector<bool>> visited(forest.size(),
                                     vector<bool>(forest[0].size(), false));
        visited[si][sj] = true;
        queue<pair<int, int>> q({make_pair(si, sj)});
        int len = 0;
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        while (true) {
            int qsize = q.size();
            while (qsize--) {
                if (q.front().first == ti &&
                    q.front().second == tj) // the function stops here
                    return len;
                for (int k = 0; k < 4; ++k) {
                    int i = q.front().first + di[k];
                    int j = q.front().second + dj[k];
                    if (i >= 0 && i < forest.size() && j >= 0 &&
                        j < forest[0].size() && !visited[i][j] &&
                        forest[i][j] > 0) {
                        visited[i][j] = true;
                        q.push(make_pair(i, j));
                    }
                }
                q.pop();
            }
            ++len;
        }
        return -999999; // redundancy, never goes this line
    }

    // check if there exists a shortest path avail from (x1,y1) to (x2,y2)
    // going one out of 4 directions : upper-left , upper-right , lower-left
    // , lower-right
    /*  e.g. going from S(x1,y1) to T(x2,y2), 'X' is obstacle, '*' is
       current layer lower-right direction, minumum step = 5, going step by
       step as follow [S, , , ]     [ ,*, , ]    [ , ,*, ]    [ , , ,*]    [
       , , , ] [ , , , ] [ , ,X, ] ->  [*, ,X, ] -> [ ,*,X, ] -> [ , ,X, ]
       -> [ , ,X,*]
       -> [ , ,X, ] [X, , ,T]     [X, , , ]    [X, , , ]    [X,*, , ]    [X,
       ,*, ]    [X, , ,*] step 1       step 2       step 3       step 4
       step 5
    */
    bool ShortestPathAvailable(int x1, int y1, int x2, int y2,
                               const vector<vector<int>> &forest) {
        int dx = (x2 > x1) ? 1 : -1;
        int dy = (y2 > y1) ? 1 : -1;
        int minstep = abs(x1 - x2) + abs(y1 - y2);
        queue<pair<int, int>> q({make_pair(x1, y1)});
        while (minstep--) {
            int qsize = q.size();
            if (qsize == 0)
                return false; // haven't gone minstep yet, but no path
                              // available
            while (qsize--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x != x2 && forest[x + dx][y] > 0 &&
                    ((x + dx) != q.back().first || y != q.back().second))
                    q.push(make_pair(x + dx, y));
                if (y != y2 && forest[x][y + dy] > 0 &&
                    (x != q.back().first || (y + dy) != q.back().second))
                    q.push(make_pair(x, y + dy));
            }
        }
        // if true return, only destination [x2,y2] is in the queue
        return q.size() == 1;
    }
};

// A*的解法
// https://leetcode.com/problems/cut-off-trees-for-golf-event/discuss/107415/my-python-solution-inspired-by-A*-algorithm