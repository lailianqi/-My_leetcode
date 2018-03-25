#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// python的解法
// https://leetcode.com/problems/pyramid-transition-matrix/discuss/113038/Easy-and-Concise-Python-solution
/*
from collections import defaultdict
from itertools import product

class Solution(object):

    def pyramidTransition(self, bottom, allowed):
        f = defaultdict(lambda: defaultdict(list))
        for a, b, c in allowed: f[a][b].append(c)

        def pyramid(bottom):
            if len(bottom) == 1: return True
            for i in product(*(f[a][b] for a, b in zip(bottom, bottom[1:]))):
                if pyramid(i): return True
            return False
        return pyramid(bottom)
*/

// 比较简单的写法
// https://leetcode.com/problems/pyramid-transition-matrix/discuss/113036/A-map-based-solution-based-on-memoization
// 第二个链接是上面解法的复杂版
// https://leetcode.com/problems/pyramid-transition-matrix/discuss/113054/Java-solution-map-+-backtracking
class Solution_0 {
  public:
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        unordered_map<string, string> _map;
        for (string str : allowed) {
            _map[str.substr(0, 2)] += str.back();
        }
        return dfs(bottom, "", _map);
    }

    bool dfs(string bottom, string above, unordered_map<string, string> &_map) {
        if (bottom.size() == 2 && above.size() == 1)
            return true;
        if (bottom.size() == above.size() + 1)
            return dfs(above, "", _map);
        int cur = above.size();
        string base = bottom.substr(cur, 2);
        for (char c : _map[base]) {
            if (dfs(bottom, above + c, _map))
                return true;
        }
        return false;
    }
};