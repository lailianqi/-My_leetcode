#include <vector>
#include <algorithm>
using namespace std;
//自己的第一个写法 用的贪心的思想 成功ac
//发现leetcode的答案和我的思想以及第一个写法基本上一模一样
// https://discuss.leetcode.com/topic/67676/simple-greedy-java-solution
// https://discuss.leetcode.com/topic/68455/array-sort-two-pointer-greedy-solution-o-nlogn
class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size();) {
            if (g[i] <= s[j]) {
                i++, j++, res++;
            } else {
                j++;
            }
        }
        return res;
    }
};
//上面的稍微的代码精简版
class Solution_1 {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        for (; i < g.size() && j < s.size(); j++) {
            if (g[i] <= s[j]) {
                i++;
            }
        }
        return i;
    }
};