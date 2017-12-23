#include <string>
#include <vector>
#include <map>
using namespace std;
// 自己的第一种解法 一次性ac 但是感觉自己的代码太长了
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char, int> dir, record;
        int m = s.size(), n = p.size();
        for (int i = 0; i < n; i++) {
            dir[p[i]]++;
        }
        for (int i = 0; i < m; i++) {
            record[s[i]]++;
            if (i >= n - 1) {
                auto it = dir.begin();
                while (it != dir.end() && dir[it->first] == record[it->first]) {
                    it++;
                }
                if (it == dir.end()) {
                    res.push_back(i - n + 1);
                }
                record[s[i - n + 1]]--;
            }
        }
        return res;
    }
};

//自己对上面代码的稍微的改进版
// leetcode有帖子和下面的解法的思想差不多 但是代码比下面长
// https://discuss.leetcode.com/topic/64390/c-o-n-sliding-window-concise-solution-with-explanation
//下面这个链接运行速度可能更快一点 思想可能更加的优秀 有dp的思想在里面
// https://discuss.leetcode.com/topic/64434/shortest-concise-java-o-n-sliding-window-solution
class Solution_0 {
  public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> res, dir(26, 0), record(26, 0);
        for (int i = 0; i < n; i++) {
            dir[p[i] - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            record[s[i] - 'a']++;
            if (i >= n - 1) {
                if (dir == record) { // c++已经重载了判断容器是否相等的运算符
                    res.push_back(i - n + 1);
                }
                record[s[i - n + 1] - 'a']--;
            }
        }
        return res;
    }
};
