#include <vector>
#include <map>
using namespace std;
//自己直接采用暴力的解法  效率一般 为O(n^2)但是成功ac
// leetcode相同思想的答案
// https://discuss.leetcode.com/topic/66587/clean-java-solution-o-n-2-166ms
class Solution {
  public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int res = 0;
        map<int, int> dir;
        for (int i = 0; i < points.size(); i++) {
            dir.clear();
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    dir[getDistance(points[i], points[j])]++;
                }
            }
            for (auto element : dir) {
                res += (element.second) * (element.second - 1);
            }
        }
        return res;
    }
    int getDistance(pair<int, int> &a, pair<int, int> &b) {
        return (a.first - b.first) * (a.first - b.first) +
               (a.second - b.second) * (a.second - b.second);
    }
};

// sp大神的解法
// https://discuss.leetcode.com/topic/66574/7-lines-1050-ms-c/8