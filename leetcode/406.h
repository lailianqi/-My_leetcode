#include <vector>
#include <algorithm>
using namespace std;
//第一次没有想到思路  真是非常的惭愧 不应该啊
// leetcode的答案
// https://discuss.leetcode.com/topic/60394/easy-concept-with-python-c-java-solution/4
class Solution {
  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        vector<pair<int, int>> res;
        auto cmp = [](pair<int, int> p, pair<int, int> q) {
            return p.first > q.first ||
                   (p.first == q.first && p.second < q.second);
        };
        sort(people.begin(), people.end(), cmp);
        for (auto per : people) {
            res.insert(res.begin() + per.second, per);
        }
        return res;
    }
};

// sp大神的解法
// https://discuss.leetcode.com/topic/60981/explanation-of-the-neat-sort-insert-solution